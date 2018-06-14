#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100 
#define QElemType  int
typedef struct
{
	 QElemType *base;
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue &Q)//����һ���ն�
{
	Q.base = (QElemType *)malloc(MAXSIZE *sizeof(QElemType));
	if (!Q.base)
		exit(0);
	Q.front = Q.rear = 0;
}

void InQueue(SqQueue &Q, QElemType e)//��ӣ������ж϶������
{
	int x;
	printf("������һ������:");
	scanf("%d", &x);
	if (Q.front == (Q.rear + 1) % MAXSIZE)
	{
		printf("���������ʧ�ܣ�\n");
		exit(0);                //��ֹ����
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	printf("��ӳɹ���\n");
}

void OutQueue(SqQueue &Q, QElemType e)//���ӣ����жϴ˶����Ƿ�Ϊ��
{
	if (Q.front == Q.rear)
	{
		printf("�˶���Ϊ��!");
		exit(0);
	}
	else
	{
		Q.front = (Q.front + 1) % MAXSIZE;
		printf("����Ԫ��Ϊ��%d\n", Q.base[Q.front]);
		exit(0);
	}
}

void showQueue(SqQueue &Q)//�������
{
	int k = Q.front;
	if (k == Q.rear)
	{
		printf("�˶�Ϊ��!\n");
		exit(0);
	}
	printf("�˶�Ԫ��Ϊ:");
	do
	{
		k = (k + 1) % MAXSIZE;
		printf("%d", Q.base[k]);
	} while (k != Q.rear);
	printf("\n");
}

void main()              //������
{
	int e;
	SqQueue Q;
	InitQueue(Q);
	InQueue(Q, e);
	OutQueue(Q, e);
	showQueue(Q);
}
