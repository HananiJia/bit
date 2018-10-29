//这是一个通过自定制协议来实现的网络计算器
//客户端传输过来的数据是提前协定好的
//服务端进行解析之后得到结果返回客户端
//1.创建socket  socket
//2.绑定地址  bind
//3.开始监听  listen
//4.接受收客户端链接  accept
//5.接受客户端的数据
//6.以指定的协议来对数据进行解析
//7.进行计算
//8.返回结果
//9.关闭socket


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//我们自己设定协议格式
//前四个自己是一个数字
//之后四个字节是另一个数字
//最后一个字节是运算符

typedef struct _cal_req_t
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
    struct sockaddr_in lst_addr;
    struct sockaddr_in cli_addr;
    int lst_fd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(lst_fd<0)
    {
        perror("socket error\n");
        return -1;
    }
    lst_addr.sin_family=AF_INET;
    lst_addr.sin_port=htons(atoi(argv[2]));
    lst_addr.sin_addr.s_addr=inet_addr(argv[1]);
    socklen_t len=sizeof(struct sockaddr_in);
    int ret=bind(lst_fd,(struct sockaddr*)&lst_addr,len);
    if(ret<0)
    {
        perror("bind error\n");
        return -1;
    }
    if(listen(lst_fd,5)<0)
    {
        perror("listen error\n");
        return -1;
    }
    while(1)
    {
        int new_fd=accept(lst_fd,(struct sockaddr*)&cli_addr,&len);
        if(new_fd<0)
        {
            perror("accept error\n");
            continue;
        }
        //接受我们特定格式的数据然后开始解析
        cal_req_t req;
        char buff[1024]={0};
        ssize_t rlen=recv(new_fd,(void*)&req,1024,0);
        if(rlen<0)
        {
            perror("recv error\n");
            close(new_fd);
            continue;
        }else if(rlen==0)
        {
            printf("shutdown\n");
            close(new_fd);
        } 
        int sum=0;
        if(req.sym=='+')
        {
            sum=req.x+req.y;
        }
        if(req.sym=='-')
        {
            sum=req.x-req.y;
        }
        if(req.sym=='*')
        {
            sum=req.x*req.y;
        }
        if(req.sym=='/')
        {
            sum=req.x/req.y;
        }
        send(new_fd,(void*)&sum,4,0);
        close(new_fd);
    }
    return 0;
}
