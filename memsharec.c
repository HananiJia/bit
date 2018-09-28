#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define IPC_KEY 0X12345678

int main()
{
    int shmid=-1;
    shmid=shmget(IPC_KEY,32,IPC_CREAT|0664);
    //通过shmat函数来创建共享内存
    //第一个参数是建立共享对象的key值
    //第二个参数是创建共享内存的大小
    //第三个参数是如果不存在则创建，存在的话就打开，0664是创建文件的权限
    if(shmid<0)
    {
     perror("shmget errno\n");
     return -1;
    }
    void* shm_start=shmat(shmid,NULL,0);
    //shmat函数是将我们共享内存映射到虚拟空间地址
    //第一个参数是我们的操作句柄
    //第二个参数是映射的地址空间，如果传入NULL，操作系统会自动给分配一个
    //第三个参数是读写权限，如果是SHM_RDONLY为只读，否则是读写
    if(shm_start==(void*)  -1)
    {
        perror("shmat error\n");
        return -1;
    }
    while(1)
    {
     printf("%s\n",(char *)shm_start);
     sleep(1);
    }
    //通过while循环来实现从共享内存中读取数据
    shmdt(shm_start);
    //shmdt是用来解除我们的内存映射，参数是我们共享内存的地址空间
    shmctl(shmid,IPC_RMID,NULL);
    //shmctl是来删除我们创建的共享内存
    //第一个参数shmid是我们的描述符，第二个参数就代表着删除，第三个参数用来接收共享内存描述的信息，不关系就传入NULL
    return 0;
}
