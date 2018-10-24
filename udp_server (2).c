//这个是UDP协议聊天程序的服务端

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    int sockfd=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    if(sockfd<0)
    {
        perror("socket error\n");
        return -1;
    }
    struct sockaddr_in ser_addr;
    ser_addr.sin_family=AF_INET;
    ser_addr.sin_port=htons(9000);
    ser_addr.sin_addr.s_addr=inet_addr("192.168.76.130");
    socklen_t len=sizeof(struct sockaddr_in);
    int ret=bind(sockfd,(struct sockaddr*)&ser_addr,len);
    //bind 函数将所创建的套接字绑定到一个地址并且赋予一个端口号 
    //第一个参数是套接字描述符，
    //第二个参数为要绑定的地址信息
    //第三个参数为地址信息的长度。
    //返回-1代表绑定失败
    if(ret<0)
    {
        perror("bind error\n");
        close(sockfd);
        return -1;
    }
    while(1)
    {
        //接受数据
        char buff[1024]={0};
        struct sockaddr_in cli_addr;
        len=sizeof(struct sockaddr_in);
        ssize_t rlen=recvfrom(sockfd,buff,1023,0,(struct sockaddr*)&cli_addr,&len);
        if(rlen<0)
        {
            perror("recvfrom error\n");
            close(sockfd);
            return -1;
        }
        printf("client:%s %d say:%s\n",inet_ntoa(cli_addr.sin_addr),ntohs(cli_addr.sin_port),buff);
        memset(buff,0x00,1024);
        scanf("%s",buff);
        sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,len);

    }
    close(sockfd);
    return -1;
}
