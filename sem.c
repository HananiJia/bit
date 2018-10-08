//这是实现信号量互斥操作的程序

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>

#define IPC_KEY 0X12345678
union sem {
    int val;//信号量数值
    struct semid_ds *buf;//内核所提供的结构体
    unsigned short *array;//
    struct seminfo *_buf;
};

void sem_P(int id)
{

    struct sembuf buf;
    //sembuf结构体包含三个变量 
    //num代表信号量的编号
    //op代表一次pv操作改变的值一般是-1或者1，这里是p操作所以是-1也就是让资源量变少的
    //flg有两个选项SEM_UNDO是让操作系统跟踪信号，并在进程没有释放改信号而终止的时候，操作系统将其释放
    buf.sem_num=0;
    buf.sem_op=-1;
    buf.sem_flg=SEM_UNDO;

    semop(id,&buf,1);
    //semop是用来创建和访问一个信号量集
    //第一个是semop的操作信号量表示码也就是semget的返回值
    //第二个是指向一个结构数值的指针
    //第三个是信号量的个数
}
void sem_V(int id)
{
    struct sembuf buf;
    buf.sem_num=0;
    buf.sem_op=1;//这里是V操作是让信号量加1的所以这里是1
    buf.sem_flg=SEM_UNDO;
    semop(id,&buf,1);
}
int main()
{
    int semid=semget(IPC_KEY,1,IPC_CREAT|0664);
    //semget创建一个信号量
    //第一个参数是信号量的标识
    //第二个参数是要创建的信号量个数
    //第三个参数和之前创建文件管道等等的作用是一样的
    if(semid<0)
    {
        perror("semget error\n");
        return -1;
    }
    union sem semval;
    semval.val=1;
    semctl(semid,0,SETVAL,semval);
    //semctl函数给信号量设置初值并且只能设置一次
    //第一个参数是信号量的标识
    //第二个参数是操作第几个信号量
    //之后的参数是不固定的，是用来表示对信号量要做些什么的操作
    //SETVAL代表设置信号量的数值，STEALL代表设置所有信号量的数值这时候第二个参数将被忽略
    //如果要获取信号量的数值第四个参数就是结构体，如果要给信号量设置初值那么放得就是值的联合体
    int pid=-1;
    pid=fork();
    if(pid<0)
    {
        perror("fork error\n");
        return -1;
    }
    else
    {
        if(pid==0)
        {
            sleep(1);
            while(1)
            {
                sem_P(semid);
                //因为我们设置的是一元的信号量，所以在这里进行p操作的时候信号量的数值就会变成0
                //这时候其他进程就不能再去访问
                printf("A");
                fflush(stdout);
                sleep(1);
                printf("A");
                fflush(stdout);
                sem_V(semid);
                //我们操作完成后释放掉我们的信号量这时候其他进程就可以操作了
            }
        }
        else
        {
            while(1)
            {
                sem_P(semid);
                printf("B");
                fflush(stdout);
                sleep(1);
                printf("B");
                fflush(stdout);
                sem_V(semid);
            }
        }
    }

   return 0;
}

