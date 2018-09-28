#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define IPC_KEY 0x12345678

int main()
{
  int shmid=-1;
  shmid=shmget(IPC_KEY,32,IPC_CREAT|0664);
  if(shmid<0)
  {
   perror("shmget error\n");
   return -1;
  }
  void* shm_start=shmat(shmid,NULL,0);
  if(shm_start==(void*)-1)
  {
      perror("shmat error\n");
      return -1;
  }
  while(1)
  {
     printf("please input \n");
     fflush(stdout);
     memset(shm_start,0x00,32);
     scanf("%s",(void *)shm_start);
     sleep(1);
  }
  shmdt(shm_start);
  shmctl(shmid,IPC_RMID,NULL);
  return 0;
}
