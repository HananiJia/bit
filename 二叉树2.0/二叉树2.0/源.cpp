
#include<stdio.h>
#include<stdlib.h>
typedef struct BiNode
{
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;

}BiNode, *BiTree;
int CreatBiTree(BiTree &T)
{
	int m;
	scanf("%d", &m);
	if (m == -1)
		T=NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiNode));
		T->data = m;
		printf("请输入%d的左孩子", m);
		CreatBiTree(T->lchild);
		printf("请输入%d的右孩子", m);
		CreatBiTree(T->rchild);
	}
	return 0;

}
void  PrintfBiTree(BiTree T)
{
	if (T == NULL)
		return;
	printf("%d", T->data);
	PrintfBiTree(T->lchild);
	PrintfBiTree(T->rchild);

}

int main()
{
	BiTree T;
	BiTree *p = (BiTree*)malloc(sizeof(BiNode));
	printf("请输入根节点的值，当任何节点为-1时代表为空节点\n");
	CreatBiTree(T);
	PrintfBiTree(T);
	system("pause");

}