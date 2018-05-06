#include<stdio.h>
#include<stdlib.h>
/*用有序链表实现集合的并、交、差运算；*/
typedef int ElemType;//数据类型
typedef int status;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
int n;//数据元素的个数
int m = sizeof(LNode);
//创建链表
status InitList(LNode *head)
{
	int a;
	printf("请输入要输入的数字个数：");
	scanf_s("%d", &a);
	getchar();
	LNode *p;
	int i;
	p = (LinkList)malloc(m);//循环外给首源节点开辟存储空间
	printf("请输入要输入的第%d数字", 1);
	head->next = p;

	scanf_s("%d", &p->data);
	getchar();
	for (i = 1; i<a; i++)
	{
		p->next = (LinkList)malloc(m);//为后继结点开新空间！
		p = p->next; //让指针变量P改为指向后继结点
		printf("\n请输入要输入的第%d数字", i + 1);
		scanf_s("%d", &p->data);
		getchar();
	}
	p->next = NULL;//单链表尾结点的指针域要置空！
	return 1;
}
//显示
status PrintfList(LNode *L)
{
	LNode *p;
	p = L;
	while (p->next)        /*  只要没到最后一个元素，就不停地输出 输出*/
	{
		p = p->next;
		printf("%3d", p->data);
	}
	printf("\n");
	return 1;
}
//并集
LNode* MergeList(LNode *La, LNode *Lb)
{
	LNode *pa, *pb, *pc;
	LNode *c = (LNode*)malloc(m);
	pa = La->next; pb = Lb->next;
	pc = c;
	while (pa&&pb)
	{
		if (pa->data < pb->data)//比较排序
		{
			//printf("aaaaaaaaaaaaaaaaaaaa\n");
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
			PrintfList(La);//显示
		}
		if (!pa || !pb)break;
		if (pa->data == pb->data)
		{
			//printf("bbbbbbbbbbbbbbbbbbbbb\n");
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
			pb = pb->next;
			PrintfList(La);
		}
		if (!pa || !pb)break;
		if (pa->data > pb->data)
		{
			//printf("cccccccccccccccccc\n");
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
			PrintfList(La);
		}
	}
	PrintfList(La);
	pc->next = pa ? pa : pb;
	PrintfList(La);
	return c;
}
//交集
LNode* MixList(LNode *La, LNode *Lb)
{
	LNode *pa, *pb, *pc;
	LNode *c = (LNode*)malloc(m);
	pa = La; pb = Lb;
	pa = pa->next; pb = pb->next;
	pc = c;
	while (pa)
	{
		while (pb)
		{
			if (pa->data == (pb->data))
			{
				pc->next = pa;
				pc = pc->next;
			}
			pb = pb->next;
		}
		pa = pa->next;
		pb = Lb->next;
	}
	pc->next = NULL;
	return c;
}
//补集
LNode *AddList(LNode *La, LNode *Lb)
{
	LNode *pa, *pb, *ha;
	pa = La; pb = Lb;
	ha = La;
	pa = pa->next; pb = pb->next;
	while (pb)
	{
		while (pa)
		{
			if (pa->data == (pb->data))
			{
				ha->next = pa->next; break;
			}
			ha = pa;
			pa = pa->next;
		}
		pb = pb->next;
		pa = La->next;
	}
	return La;
}

int main()
{
	LNode *la, *lb;
	la = (LNode*)malloc(m);
	lb = (LNode*)malloc(m);
	la->data = -1;
	lb->data = -1;
	InitList(la);
	PrintfList(la);
	InitList(lb);
	PrintfList(lb);
	//PrintfList(MergeList(la, lb));
	//PrintfList(MixList(la, lb));
	PrintfList(AddList(la, lb));
	system("pause");
}