
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
		printf("������%d������", m);
		CreatBiTree(T->lchild);
		printf("������%d���Һ���", m);
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
	printf("��������ڵ��ֵ�����κνڵ�Ϊ-1ʱ����Ϊ�սڵ�\n");
	CreatBiTree(T);
	PrintfBiTree(T);
	system("pause");

}