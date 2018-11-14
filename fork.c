#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<string.h>

int val=100;
int main()
{
    int id=fork();
    if(id<0)
    {
        perror("fork error\n");
        return -1;
    }
    else
    {
        if(id==0)
        {
            val=200;
            printf("child pid:%d val:%d ad:%p\n",getpid(),val,&val);
            sleep(3);
        }
        else
        {
            printf("parent pid:%d val:%d ad:%p\n",getpid(),val,&val);
        }
    }
    return 0;
}
