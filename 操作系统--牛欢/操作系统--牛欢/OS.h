#ifndef __OS_H__
#define __OS_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 4

typedef struct PCB{
	char Name;//进程名
	int ArriveTime;//到达时间
	int ServerTime;//服务时间
	int Time;//时间片
	int Front;//优先级
	int StartTime;//开始执行时间
	int FinishTime;//完成时间
	int WholeTime;//周转时间
	int ValueWholeTime;//带权周转时间
	struct PCB* next;
}_PCB;

void InitPcb(_PCB** pcb);//初始化
_PCB* BuyNode(_PCB* pcb);
void PushFront(_PCB** pcb);//头插
void Screen();//界面
void Input(_PCB** pcb);//输入函数
void Print(_PCB** pcb);//打印
void Server(int n, _PCB** pcb);
void OrderServer(_PCB** pcb);//先来先服务
void PriorityServer();//优先级服务
void RotateServer();//时间片轮转服务


#endif //__OS_H__