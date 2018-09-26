//这是消息队列服务端的实现

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define IPC_TYPE 0x22345678
#define TYPE_S 1
#define TYPE_C 2

struct msgbuf
{
   long type;
   char buf[1024];
};

int main()
{
    int msgid=-1;
    msgid=msgget(IPC_TYPE,IPC_CREAT|0664);
    if(msgid<0)
    {
        perror("msgget error\n");
        return -1;
    }
    while(1)
    {
      struct msgbuf buff;
	  //接受数据
      memset(&buff,0x00,sizeof(struct msgbuf));
     msgrcv(msgid,&buff,1024,TYPE_C,0);
     printf("client say:%s\n",buff.buf);
	 //发送数据
      memset(&buff,0x00,sizeof(struct msgbuf));
      buff.type=TYPE_S;
      scanf("%s",buff.buf);
      msgsnd(msgid,&buff,1024,0);
    }
    msgctl(msgid,IPC_RMID,NULL);

}
