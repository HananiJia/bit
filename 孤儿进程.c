#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main()
{
   pid_t id=fork();
   if(id<0)
   {
       perror("fork erroe\n");
       return -1;
   } else if(id==0)
   {
       printf("child: %d\n",getpid());
       sleep(30);
   }
   else
   {
     printf("parent: %d\n",getpid());
     sleep(6);
     exit(0);
   }
   return 0;
}
