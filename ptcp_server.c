//这是一个实现多线程TCP的聊天程序服务端

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/socket.h>
#include<pthread.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void *thr_start(void *arg)
{
    int clifd=(int)arg;
    while(1)
    {
        char buff[1024]={0};
        ssize_t ret=recv(clifd,buff,1024,0);
        if(ret<0)
        {
            perror("recv error\n");
            close(clifd);
            break;
        }
        else if(ret==0)
        {
            printf("client shutdown\n");
        }
        printf("client say:%s\n",buff);
        send(clifd,"over",4,0);
    }
    return NULL;
}
int create_worker(int clifd)
{
    pthread_t tid;//创建一个线程来单独处理与某个客户端的通信
    int ret=pthread_create(&tid,NULL,thr_start,(void*)clifd);
	//pthread_create函数用来创建线程
	//第一个参数是指向线程标识符的指针
	//第二个参数是用来设置线程的属性默认为NULL
	//第三个参数为创建出来的线程从哪里开始执行，我们这里创造出来的线程就直接去执行thr_start函数了
	//第四个参数是运行第三个函数的参数
    if(ret!=0)
    {
        printf("pthread_create error\n");
        return -1;
    }
    return 0;
}
int main(int argc,char* argv[])
{
    if(argc!=3)
    {
        printf("please input\n");
        return -1;
    }
    int lstfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(lstfd<0)
    {
        printf("socket error\n");
        return -1;
    }
    struct sockaddr_in lst_addr;
    struct sockaddr_in cli_addr;
    lst_addr.sin_family=AF_INET;
    lst_addr.sin_port=htons(atoi(argv[2]));
    lst_addr.sin_addr.s_addr=inet_addr(argv[1]);
    socklen_t len=sizeof(struct sockaddr_in);
    int ret=bind(lstfd,(struct sockaddr*)&lst_addr,len);
    if(ret<0)
    {
    perror("bind error\n");
    return -1;
    }
    if(listen(lstfd,5)<0)
    {
       perror("listen error\n");
       return -1;
    }
    while(1)
    {
      int  clifd=accept(lstfd,(struct sockaddr*)&cli_addr,&len);
       if(clifd<0)
       {
         perror("accept error\n");
         continue;
       }
       create_worker(clifd);
	   //接受到了socket就通过创建线程来实现
    }
    return 0;
}

