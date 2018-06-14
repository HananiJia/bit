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

void InitQueue(SqQueue &Q)//构建一个空队
{
	Q.base = (QElemType *)malloc(MAXSIZE *sizeof(QElemType));
	if (!Q.base)
		exit(0);
	Q.front = Q.rear = 0;
}

void InQueue(SqQueue &Q, QElemType e)//入队，并且判断队满情况
{
	int x;
	printf("请输入一个数据:");
	scanf("%d", &x);
	if (Q.front == (Q.rear + 1) % MAXSIZE)
	{
		printf("队满，入队失败！\n");
		exit(0);                //终止程序
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	printf("入队成功！\n");
}

void OutQueue(SqQueue &Q, QElemType e)//出队，并判断此队列是否为空
{
	if (Q.front == Q.rear)
	{
		printf("此队列为空!");
		exit(0);
	}
	else
	{
		Q.front = (Q.front + 1) % MAXSIZE;
		printf("出队元素为：%d\n", Q.base[Q.front]);
		exit(0);
	}
}

void showQueue(SqQueue &Q)//输出函数
{
	int k = Q.front;
	if (k == Q.rear)
	{
		printf("此队为空!\n");
		exit(0);
	}
	printf("此队元素为:");
	do
	{
		k = (k + 1) % MAXSIZE;
		printf("%d", Q.base[k]);
	} while (k != Q.rear);
	printf("\n");
}

void main()              //主函数
{
	int e;
	SqQueue Q;
	InitQueue(Q);
	InQueue(Q, e);
	OutQueue(Q, e);
	showQueue(Q);
}
