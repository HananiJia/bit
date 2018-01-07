#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct BiNodeTree
{
	char data;
	struct BiNodeTree *lchild;
	struct BiNodeTree *rchild;

}BiNodeTree, *BiTree;

int CreatBiTree(BiTree &T)
{
	int m;
	scanf("%d", &m);
	if (m == -1)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiNodeTree));
		T->data = m;
		printf("请输入%d的左孩子", m);
		CreatBiTree(T->lchild);
		printf("请输入%d的右孩子", m);
		CreatBiTree(T->rchild);

	}
	return 0;

}

void PrintfBiTree(BiTree T)
{
	
	while (T)
	{
		printf("%d", T->data);
		printf("%d", T->lchild);
		printf("%d", T->rchild);
	}
	
	  
}
int main()
{
	BiTree T;
	BiTree *p = (BiTree*)malloc(sizeof(BiNodeTree));
	printf("请输入根节点的值，当任何节点为-1时代表为空节点\n");
	CreatBiTree(T);
	PrintfBiTree(T);
}
