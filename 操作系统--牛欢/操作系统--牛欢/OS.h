#ifndef __OS_H__
#define __OS_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 4

typedef struct PCB{
	char Name;//������
	int ArriveTime;//����ʱ��
	int ServerTime;//����ʱ��
	int Time;//ʱ��Ƭ
	int Front;//���ȼ�
	int StartTime;//��ʼִ��ʱ��
	int FinishTime;//���ʱ��
	int WholeTime;//��תʱ��
	int ValueWholeTime;//��Ȩ��תʱ��
	struct PCB* next;
}_PCB;

void InitPcb(_PCB** pcb);//��ʼ��
_PCB* BuyNode(_PCB* pcb);
void PushFront(_PCB** pcb);//ͷ��
void Screen();//����
void Input(_PCB** pcb);//���뺯��
void Print(_PCB** pcb);//��ӡ
void Server(int n, _PCB** pcb);
void OrderServer(_PCB** pcb);//�����ȷ���
void PriorityServer();//���ȼ�����
void RotateServer();//ʱ��Ƭ��ת����


#endif //__OS_H__