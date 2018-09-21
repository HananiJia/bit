#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
//实现匿名管道
int main()
{
    int fd[2];
    if(pipe(fd)<0)
       {
           perror("pipe error\n");
           return -1;
       }
    int pid=-1;
    pid=fork();//创建一个子进程
    if(pid<0)
    {
        perror("pid error\n");
        return -1;
    }
    if(pid==0)
     {
         //进来说明是子进程，我们让子进程来读取数据
        close(fd[1]);//管道是半双工、单向所以需要关掉一个,这里关掉的是fd【1】写入数据的文件描述符
        char buff[1024];
        sleep(5);
        read(fd[0],buff,1024);
        printf("child: %s\n",buff);
        close(fd[0]);
     }
    else
    {
        //这个进来的是父进程
        close(fd[0]);
        write(fd[1],"hello ",6);
        write(fd[1],"world ",6);
        write(fd[1],"pipe ",5);
        close(fd[1]);
    }
    return 0;
}
