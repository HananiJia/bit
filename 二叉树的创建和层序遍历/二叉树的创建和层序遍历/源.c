#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode
{
	struct BiNode *lchild;
	struct BiNode *rchild;
	char data;
}BiNode, *BiTree;
void CreatBiTree()
{
	int m = 0;
	scanf("%d", &m);
	if (m == -1)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiNode));
		T->data = m;
		printf("������%d������", T->data);
		CreatBiTree(T->lchild);
		printf("������%d���Һ���", T->data);
		CreatBiTree(T->rchild);
	}
}
typedef struct
{
	int *base;
	int front;
	int rear;
}SqQueue;
