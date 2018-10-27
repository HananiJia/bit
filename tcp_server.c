//这是TCP协议来实现服务端的程序
//1.创建socket
//2.为socket绑定地址
//3.开始监听，可以接受客户端的链接请求
//4.获取连接成功的socket
//5.接受数据
//6.发送数据
//7.关闭socket
//
//
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc,char *argv[])
{
   if(argc!=3)
   {
       printf("please input:tcp ip port\n");
       return -1;
   }
   int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   if(sockfd<0)
   { 
      perror("socker error\n");
      return -1;
   }
   struct sockaddr_in ser_addr;
   ser_addr.sin_family=AF_INET;
   ser_addr.sin_port=htons(atoi(argv[2]));
   ser_addr.sin_addr.s_addr=inet_addr(argv[1]);
   socklen_t len=sizeof(struct sockaddr_in);
   int ret=bind(sockfd,(struct sockaddr*)&ser_addr,len);
   //为socket绑定地址
   if(ret<0)
   {
   perror("bind error\n");
   return -1;
   }
   //服务端开始监听 这时候服务端可以请求链接
   if(listen(sockfd,5)<0)
   {
      //listen 函数服务端用来监听
      //第一个参数为socket描述符
      //第二个参数为 最大的同时并发连接数
      perror("listen error\n");
      return -1;
   }
   while(1)
   {
      int new_sockfd; 
      struct sockaddr_in addr;
      len=sizeof(struct sockaddr_in);
      new_sockfd=accept(sockfd,(struct sockaddr*)&addr,&len);
      //获取连接成功的socket int accept
      //第一个参数为socket描述符
      //第二个参数为新建立链接的客户端地址信息
      //第三个参数为地址信息的长度
      //返回值如果成功返回新的描述符，如果失败返回-1
      //accept是一个阻塞函数链接成功队列中如果没有新的链接
      //那就会一直阻塞直到有新的客户端链接到来
      //这里我们通过创新新的socket来接受数据
      //客户端发送的数据都在这个新的socket缓冲区中
      //以前的socket被用来处理链接，链接成功的socket
      //发送数据都在新的socket的缓冲区
      if(new_sockfd<0)
      {
          perror("accept error\n");
          continue;//这里不能直接退出，因为这个链接失败了可以链接别的socket
      }
      printf("new socket:%s,%d,\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
      //这里我们输出一下链接过来的socket的ip地址和port端口号
      while(1)
      {
          //接受数据
          char buff[1024]={0};
          ssize_t rlen=recv(new_sockfd,buff,1023,0);
          //recv 接受数据 
          //第一个为sockfd描述符
          //第二个参数为接受数据的缓冲区
          //第三个为接受数据的长度
          //第四个参数为0是代表阻塞式接受
          //对于返回值有三种情况 如果错误返回-1，链接关闭返回0，正确的话返回的是接受的长度
          if(rlen<0)
          {
              perror("recv error\n");
              close(new_sockfd);
              continue;//这里和客户端不同不能直接关闭你的程序
          }
          else if(rlen==0)
          {
              printf("perr shutdown\n");
              close(new_sockfd);
              continue;//如果返回0的话代表那个链接断开了
          }
          printf("client %s:%d say:%s\n",inet_ntoa(addr.sin_addr),ntohs(addr.sin_port),buff);
          //发送数据
          memset(buff,0x00,1024);
          scanf("%s",buff);
          send(new_sockfd,buff,strlen(buff),0);
      }
   }

     close(sockfd);
     return 0;
}
