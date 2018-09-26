//实现进程间通信---消息队列的客户端程序


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/msg.h>
#include<sys/ipc.h>

#define  IPC_KEY 0X12345678
//这是消息队列的key 在内核中消息队列的标识符 可以设定为常数也可以通过ftok函数来获取
//ftok（const char *pathname，int proj_id）函数会通过文件的inode结点和proj_id来计算出来一个数值
//但是这个函数有一个缺点如果文件被删除或替换掉可能会打开不同的消息队列导致出错

#define TYPE_S 1
#define TYPE_C 2
//用来定义我们在通信的时候什么是服务端什么是客户端

struct msgbuf{
    long type;//消息的类型
    char buf[1024];//消息的内容
};

int main()
{
  int msgid=-1;
  msgid=msgget(IPC_KEY,IPC_CREAT|0664);
  //int msgget(IPC_KEY,msgflg);key是消息队列的标识符
  //msgflg可以是 IPC_CREAT代表如果不存在消息队列就创建，存在就打开
  //IPC_EXCL 和creat搭配使用，如果存在则会报错
  //mode 是创建的权限
  if(msgid<0)
  {
      perror("msgget error\n");
      return -1;
  }
  while(1)
  {
     struct msgbuf  buff;
     //发送数据
      memset(&buff,0x00,sizeof(struct msgbuf));
      buff.type=TYPE_C;
      scanf("%s",buff.buf);
      msgsnd(msgid,&buff,1024,0);
      //msgsnd(用于操作的句柄，数据内容，数据长度（只是数据长度没有结构体中的数据类型的大小），通常设置为0）
      //第四个参数标志选项是用来控制如果消息队列满了或者说消息队列达到限制之后会发生的情况。通常设置为0
      //接受数据
      memset(&buff,0x00,sizeof(struct msgbuf));
      msgrcv(msgid,&buff,1024,TYPE_S,0);
      //msgrcv有五个参数，其他的都和上边的一样，第四个是标识你接受的数据类型，因为我这里是type_c客户端我就接受了标识type_s服务端的数据
      printf("server say=%s\n",buff.buf);
  }
  msgctl(msgid,IPC_RMID,NULL);
  //msgctl 函数用来控制我们的 第二个参数IPC_RMID就是删除我们所创建的消息队列，如果要删除队列第三个参数直接为空
}

