#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct A{                 //定义结构体
	char data;
	struct A *next;
}test;
void build(test * & l, char a[], int n)//单链表建立
{
	test*p;
	int i;
	l = (test*)malloc(sizeof(test));
	p = l;
	for (i = 0; i<n - 1; i++){
		p->data = a[i];
		p->next = (test*)malloc(sizeof(test));
		p = p->next;
	}
	p->data = a[n - 1];
	p->next = NULL;
}

void Sort(test * &head)//单链表元素排序
{
	test *p = head->next, *q, *r;
	if (p != NULL)
	{
		r = p->next;
		p->next = NULL;
		p = r;
		while (p != NULL)
		{
			r = p->next;
			q = head;
			while (q->next != NULL && q->next->data<p->data)
				q = q->next;
			p->next = q->next;
			q->next = p;
			p = r;
		}
	}
}

void Union(test *ha, test *hb, test * &hc)//求两有序集合的并
{
	test *pa = ha->next, *pb = hb->next, *s, *tc;
	hc = (test *)malloc(sizeof(test));
	tc = hc;
	while (pa != NULL && pb != NULL)
	{
		if (pa->data<pb->data)
		{
			s = (test *)malloc(sizeof(test));
			s->data = pa->data;
			tc->next = s; tc = s;
			pa = pa->next;
		}
		else if (pa->data>pb->data)
		{
			s = (test *)malloc(sizeof(test));
			s->data = pb->data;
			tc->next = s; tc = s;
			pb = pb->next;
		}
		else
		{
			s = (test *)malloc(sizeof(test));
			s->data = pa->data;
			tc->next = s; tc = s;
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pb != NULL)pa = pb;
	while (pa != NULL)
	{
		s = (test *)malloc(sizeof(test));
		s->data = pa->data;
		tc->next = s; tc = s;
		pa = pa->next;
	}
}

void InterSect(test *ha, test *hb, test * &hc)//求两有序集合的交
{
	test *pa = ha->next, *pb, *s, *tc;
	hc = (test *)malloc(sizeof(test));
	tc = hc;
	while (pa != NULL)
	{
		pb = hb->next;
		while (pb != NULL && pb->data<pa->data)
			pb = pb->next;
		if (pb != NULL && pb->data == pa->data)
		{
			s = (test *)malloc(sizeof(test));
			s->data = pa->data;
			tc->next = s; tc = s;
		}
		pa = pa->next;
	}
	tc->next = NULL;
}

void Subs(test *ha, test *hb, test * &hc)//求两有序集合的差
{
	test *pa = ha->next, *pb, *s, *tc;
	hc = (test *)malloc(sizeof(test));
	tc = hc;
	while (pa != NULL)
	{
		pb = hb->next;
		while (pb != NULL && pb->data<pa->data)
			pb = pb->next;
		if (!(pb != NULL && pb->data == pa->data))
		{
			s = (test *)malloc(sizeof(test));
			s->data = pa->data;
			tc->next = s; tc = s;
		}
		pa = pa->next;
	}
	tc->next = NULL;
}

void display(test*head){
	test*p;
	p = head->next;
	while (p->next != NULL){
		printf("%c", p->data);
		p = p->next;
	}
	printf("%c\n", p->data);
}


main(){                  //主函数，调用测试函数
	char a[] = { 'a', 'c', 'e', 'd' };
	char b[] = { 'b', 'r', 'g', 'h', 'k' };
	test*a1, *a2, *p, *q, *d;
	build(a1, a, 4);
	build(a2, b, 5);
	Union(a1, a2, q);
	InterSect(a1, a2, p);
	Subs(a1, a2, d);
	display(q);
	display(p);
	display(d);
}
