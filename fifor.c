//这是实现管道写的程序
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
  umask(0);
  if(mkfifo("./test.fifo",0664)<0)
  {
     if(errno==EEXIST)
     {
     }
     else
     {
         perror("mkfifo error\n");
         return -1;
     }
  }
  int fd=open("./test.fifo",O_RDONLY);
  if(fd<0)
  {
      perror("open error\n");
      return -1;
  }
  printf("sucess read\n");
  while(1)
  {
      char buff[1024];
    int ret=read(fd,buff,1023);
    if(ret>0)
    {
     printf("client say:%s\n",buff);
    }
    else
    {
        if(ret==0)
        {
            printf("all write port close\n");
            sleep(1);
        }
    }
  }
  close(fd);
  return 0;

}
