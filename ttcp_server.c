//这是一个实现多进程的tcp聊天程序服务端

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<string.h>
#include<error.h>
#include<signal.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int  create_work(int cli_fd)
{
    int pid=fork();
    if(pid<0)
    {
        perror("fork error\n");
        return -1;
    }
    else
    {
      if(pid==0)
      {
          //这里是新创建的子进程
		  //用创建的子进程来获取数据
          while(1)
          {
              char buff[1024]={0};
              int ret=recv(cli_fd,buff,1024,0);
              if(ret<=0)
              {
                  close(cli_fd);
                  exit(-1);
              }
              printf("client say:%s\n",buff);
              send(cli_fd,"what\?\?!!",8,0);

          }
      }else
      {
          close(cli_fd);
      }
      return 0;
    }
}
void sigcb(int signo)
{
    while(waitpid(-1,NULL,WNOHANG)>0);
    //当调用这个函数的时候我们会一直调用waitpid如果有任何子进程结束了，我们就释放他的资源
	//waitpid如果子进程结束会返回子进程结束的状态值
	//如果不在意子进程的返回值可以让第二个参数设置为NULL，我们这里并不在意
	//第一个参数
	//pid<-1 等待进程组识别码为 pid 绝对值的任何子进程。
	//pid = -1 等待任何子进程, 相当于 wait()。
	//pid = 0 等待进程组识别码与目前进程相同的任何子进程。
	//pid>0 等待任何子进程识别码为 pid 的子进程。
	//WNOHANG 若pid指定的子进程没有结束，则waitpid()函数返回0，不予以等待。若结束，则返回该子进程的ID。
}

int main(int argc,char* argv[])
{
   signal(SIGCHLD,sigcb);
   //第一个参数我们要处理的信号
   //第二个参数是我们的处理方式一般有捕获或者忽略
   //这里我们调用signal是告诉操作系统当我们收到SIGCHLD这个信号的时候处理方式为sigcb这个函数
   //SIGCHLD信号是当一个进程终止或者停止的时候会发送这个信号给父进程一般操作系统会自动忽略这个信号
   //为了防止我们创建的子进程产生僵尸进程，所以我们提前做好准备如果有这个信号就调用sigcb函数
   int lst_fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   //创建一个监听socket这个socket仅仅用于接受客户端的链接请求
   if(lst_fd<0)
   {
       perror("socket error\n");
       return -1;
   }
   struct sockaddr_in lst_addr;
   lst_addr.sin_family=AF_INET;
   lst_addr.sin_port=htons(9000);
   //htons 将两个字节的数据转换成网络字节序的数据
   lst_addr.sin_addr.s_addr=inet_addr("192.168.76.130");
   //htonl 将连个字节的数据转换层网络字节序的数据
   //ntohs 将两个字节的网络字节序数据转换为当前的主机字节序数据
   //ntohl 将四个字节的网络字节序数据转换为当前的主机字节序数据
   socklen_t len=sizeof(struct sockaddr_in);
   int ret=bind(lst_fd,(struct sockaddr*)&lst_addr,len);
   if(ret<0)
   {
       perror("bind error\n");
       return -1;
   }
   //开始监听客户端
   if(listen(lst_fd,5)<0)
   {
       perror("listen error\n");
       return -1;
   }
   //listen会在系统中开辟一个队列，第二个参数5
   //就是定义这个队列的最大结点数队列名称叫叫做链接成功队列
   //第二个参数的功能：同一时间socket的最大并发连接数
   //一旦socket开始监听，那么就可以开始接受客户端的请求
   //如果客户端的请求过来，操作系统回味这个客户端新建一个socket
   //链接成功之后会把这个socket放入链接成功队列
   //接下来如果想要和这个客户端通信，就把这个socket从队列中取出来进行操作
     while(1)
     {
         struct sockaddr_in cli_addr;
         int cli_fd=accept(lst_fd,(struct sockaddr*)&cli_addr,&len);
         if(cli_fd<0)
         {
             perror("accept error");
             continue;
         }
         create_work(cli_fd);
		 //每当我们的lst_fd这个socket接收到一个客户端的信号之后，就调用ceate_work来创建一个子进程接受数据
     }
     close(lst_fd);
     return 0;
}
