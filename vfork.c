#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
int val=100;
int main()
{
   int id=vfork();
   if(id<0)
   {
       perror("vfork error\n");
   }
   else
   {
       if(id==0)
       {
           val=200;
           printf("child pid:%d val:%d ad:%p\n",getpid(),val,&val);
           sleep(3);
           exit(1);
       }
       else
       {
           printf("parent pid:%d val:%d ad:%p\n",getpid(),val,&val);           
       }
   }
   return 0;
}
