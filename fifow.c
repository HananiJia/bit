//我们首先实现向管道文件中写入数据的程序
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>

int main()
{
  umask(0);
  if(mkfifo("/test.fifo",0664)<0)
  {
      if(errno==EEXIST)
      {
         //如果我们去创建我们的文件，返回的错误值是EEXIST代表这个文件已经存在了，这时候正常继续就可以
      }
      else
      {
           perror("mkfifo error\n");
           return -1;
      }
  }
  int fd=open("./test.fifo",O_WRONLY);
  if(fd<0)
  {
      perror("open error\n");
      return -1;
  }
  printf("sucess: write!\n");
  while(1)
  {
    char buff[1024];
    scanf("%s",buff);
    write(fd,buff,strlen(buff));
  }
  close(fd);
  return 0;
}
