#include<stdio.h>
#include<stdlib.h>
typedef struct Sqlist
{
	char data;
	struct Sqlist *next;
}Sqlist, *LinkList;
Sqlist *p, *q, *head;
int n;
int m = sizeof(Sqlist);
void bulid()
{
	int i;
	head = (Sqlist*)malloc(m);
	p = head;
	for (i = 1; i < 26; i++)
	{
		p->data = i + 'a' - 1;
		p->next = (Sqlist*)malloc(m);
		p = p->next;
	}
	p->data = i + 'a' - 1;
	p->next = NULL;
};
void printf()
{
	p = head;
	while (p->next != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("%c\n", p->data);
};
void Insert(Sqlist*head)
{
	Sqlist *h;
	p = head;
	int i;
	char s;
	printf("请输入您要插入的位置");
	scanf("%d", &i);
	getchar();
	printf("请输入您要插入的字母");
	scanf("%c", &s);
	printf("\n");
	h = (Sqlist*)malloc(m);
	h->data = s;
	p = head->next;
	int j=1;
	while (p&&j < 1)
	{
		q = p;
		p = p->next;
		j++;
	}
	if (!p || j>i)
	{

		h->next = NULL;
		q->next = h;

	}
	else
	{
		h->next = p->next;
		p ->next = h;
	}
	printf();
}
void Delete(Sqlist *head)
{
	p = head;
	int i;
	int j = 1;
	printf("请输入您要删除的位置");
	scanf("%d", &i);
	while (p->next&&j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next || j < i - 1))
		printf("出现错误");
	else
		q = p->next;
	p->next = q->next;
	free(q);
}
int main()
{
	
	bulid();
	printf();
	Insert(head);
	Delete(head);
	printf();
	system("pause");
	return 0;

}