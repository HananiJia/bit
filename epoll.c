//这是一个基于epoll多路复用的服务端

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/epoll.h>

int recv_data(int fd,char *buff)
{
    int ret;
    int alen=0;
    while(1)
    {
        ret=recv(fd,buff+alen,2,0);
        if(ret<=0)
        {
            if(errno==EAGAIN)
            {
                break;
            }
            else if(errno==EINTR)
            {
                continue;
            }
            return -1;
        }
        else if(ret<2)
        {
             break;//代表数据读取完了
        }
        alen+=ret;
    }
}


int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        perror("please ip port\n");
        return -1;
    }
    int i=0;
    char buff[1024]={0};
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0)
    {
        perror("sockfd error\n");
        return -1;
    }
    struct sockaddr_in srv_addr;
    struct sockaddr_in cli_addr;
    srv_addr.sin_family=AF_INET;
    srv_addr.sin_port=htons(atoi(argv[2]));
    srv_addr.sin_addr.s_addr=inet_addr(argv[1]);
    socklen_t len=sizeof(struct sockaddr_in);
    int ret=bind(sockfd,(struct sockaddr*)&srv_addr,len);
    if(ret<0)
    {
        perror("bind error\n");
        return -1;
    }
    if(listen(sockfd,5)<0)
    {
        perror("listen error\n");
        return -1;
    }
    int epfd=epoll_create(10);
    //在内核创建eventpoll结构 size只要大于0就可以返回的是epoll句柄
    if(epfd<0)
    {
        perror("epoll_create error\n");
        return -1;
    }
    struct epoll_event ev;
    ev.events=EPOLLIN;
    ev.data.fd=sockfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,sockfd,&ev);
    //epoll_ctl 向内核中添加事件函数
    //epfd epoll的句柄
    //第二个参数为当前要进行的操作函数
    //EPOLL_CTL_ADD 添加事件
    //EPOLL_CTL_MOD 修改事件
    //EPOLL_CTL_DEL 删除事件
    //第三个参数是所监控的文件描述符
    //第四个参数为所关联的事件
    //EPOLLIN 可读事件
    //EPOLLOUT 可写事件
    //EPOLLET  边缘触发属性
    //每当有新数据到来的时候时间就会触发，如果这次没有读取完，也就是还有数据需要处理，但是不会再进行提醒。所以这种特性下我们需要一次性把缓冲区内的数据全部读完。
    //EPOLLLT 水平触发特性
    //水平特性和边缘正好相反，只要缓冲区中有数据可以读取就不断的读，默认是水平触发特性
    while(1)
    {
        struct epoll_event evs[10];
        int nfds=epoll_wait(epfd,evs,10,3000);
        //用来设置epoll的等待时间
        //第一个参数是epoll句
        //第二个是定义的结构体数组用于获取就绪的描述事件这个时间就是我们之前添加描述符关联的时间
        //第三个参数是能够获取的最大就绪的事件个数和上边定义的数组大小相等
        //epoll最大超时等待时间 单位毫秒
        //如果返回值为-1的话代表错误。返回0代表超时。返回值大于0代表就绪的个数
        if(nfds<0)
        {
            perror("epoll_wait error");
            return -1;
        }else if(nfds==0)
        {
            printf("have no data arrived!!\n");
            continue;
        }
        for(i=0;i<nfds;i++)
        {
            if(evs[i].data.fd==sockfd)
            {
                //和select一样特殊处理监听描述符
                int new_fd=accept(sockfd,(struct sockaddr*)&cli_addr,&len);
               if(new_fd<0)
               {
                   perror("accept error\n");
                   continue;
               }
               ev.events=EPOLLIN|EPOLLET;
               ev.data.fd=new_fd;
               epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&ev);
            }
            else
            {
               char buff[1024]={0};
               ret=recv_data(evs[i].data.fd,buff);
               if(ret<=0)
               {
                   if(errno==EAGAIN||errno==EINTR)
                   {
                       continue;
                   }
                   epoll_ctl(epfd,EPOLL_CTL_DEL,evs[i].data.fd,&ev);
                   close(evs[i].data.fd);
               }
               printf("client say:%s\n",buff);
            }

        }
    }
    close(sockfd);
    return 0;
}
