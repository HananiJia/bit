#include<stdio.h>
#include<stdlib.h>
/*����������ʵ�ּ��ϵĲ������������㣻*/
typedef int ElemType;//��������
typedef int status;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
int n;//����Ԫ�صĸ���
int m = sizeof(LNode);
//��������
status InitList(LNode *head)
{
	int a;
	printf("������Ҫ��������ָ�����");
	scanf_s("%d", &a);
	getchar();
	LNode *p;
	int i;
	p = (LinkList)malloc(m);//ѭ�������Դ�ڵ㿪�ٴ洢�ռ�
	printf("������Ҫ����ĵ�%d����", 1);
	head->next = p;

	scanf_s("%d", &p->data);
	getchar();
	for (i = 1; i<a; i++)
	{
		p->next = (LinkList)malloc(m);//Ϊ��̽�㿪�¿ռ䣡
		p = p->next; //��ָ�����P��Ϊָ���̽��
		printf("\n������Ҫ����ĵ�%d����", i + 1);
		scanf_s("%d", &p->data);
		getchar();
	}
	p->next = NULL;//������β����ָ����Ҫ�ÿգ�
	return 1;
}
//��ʾ
status PrintfList(LNode *L)
{
	LNode *p;
	p = L;
	while (p->next)        /*  ֻҪû�����һ��Ԫ�أ��Ͳ�ͣ����� ���*/
	{
		p = p->next;
		printf("%3d", p->data);
	}
	printf("\n");
	return 1;
}
//����
LNode* MergeList(LNode *La, LNode *Lb)
{
	LNode *pa, *pb, *pc;
	LNode *c = (LNode*)malloc(m);
	pa = La->next; pb = Lb->next;
	pc = c;
	while (pa&&pb)
	{
		if (pa->data < pb->data)//�Ƚ�����
		{
			//printf("aaaaaaaaaaaaaaaaaaaa\n");
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
			PrintfList(La);//��ʾ
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
//����
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
//����
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