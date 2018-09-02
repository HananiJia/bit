//这是一个实现生产者与消费者同步的代码
//有一个篮子，这个篮子是判断条件，篮子里边有面
//篮子里边有面
//代表消费者可以获取面，通知生产设面已经取走了
//代表生产者需要等待
//篮子里边没有面
//代表消费者等待
//代表生产者方面，通知消费者面已经放了
//
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
pthread_cond_t cond
//卖面的
void *sale_noddle(void *arg)
{
    while(1)
    {
        sleep(1);
       printf("sale noodles\n");
       //唤醒所有等待条件变量上的进程
       //int pthread cond broadcase
       //唤醒第一个等待在条件变量上的进程
       pthread_cond_signal(&cond);
       
    }
    return NULL;
}


void *buy_noddle(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        //没有面就要等待
        //调教变量适合互斥锁搭配使用的
        //是先对互斥锁做了一个判断是否加锁，如果加锁了就解锁
        //然后陷入等待******整个过程是原子操作
        //
        //要防止的情况就是：假如没有面，但是消费者有速度比较快，先拿到锁了，那么生产者将那不打所，没办法
        //生产将会导致双方卡死
        //所以如果消费者现货区到所，那么在陷入等待之前需要解锁
        //而这里的锁我的存在是为了保护这个
        printf("buy noodles\n");
    }

    return  NULL;
}
int main()
{
pthread_t tid1,tid2;
int ret;
ret=pthread_create(&tid1,NULL,sale_noddle,NULL);
if(ret!=0)
{
    printf("pthread error\n");
    return -1;
}
ret=pthread_create(&tid2,NULL,buy_noddle,NULL);
if(ret!=0)
{
    printf("pthread error\n");
    return NULL;
}
return 0;
}
