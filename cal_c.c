//这是网络计算器的客户端我们给服务端两个数据一个操作符
//之后接受服务端返回给我们数据并且输出

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>

typedef struct cal_req_t
{
    int x;
    int y;
    unsigned char sym;
}cal_req_t;

int main(int argc,char* argv[])
{ 
   if(argc!=3)
   {
       printf("please input ip/port\n");
       return -1;
   }
   int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
   if(sockfd<0)
   {
       perror("socket error\n");
       return -1;
   }
   struct sockaddr_in addr;
   addr.sin_family=AF_INET;
   addr.sin_port=htons(atoi(argv[2]));
   addr.sin_addr.s_addr=inet_addr(argv[1]);
    socklen_t len=sizeof(struct sockaddr_in);
    int ret=connect(sockfd,(struct sockaddr*)&addr,len);
    if(ret<0)
    {
        perror("connect error\n");
        return -1;
    }
    struct cal_req_t req;
    printf("请输入第一个数字\n");
    scanf("%d",&req.x);
    printf("请输入第二个数字\n");
    scanf("%d",&req.y);
    printf("请输入运算符\n");
    scanf("%s",&req.sym);
    send(sockfd,(void*)&req,sizeof(req),0);
    int sum=0;
    recv(sockfd,(void*)&sum,4,0);
    printf("%d%c%d=%d\n",req.x,req.sym,req.y,sum);
    close(sockfd);
    return 0;
}
