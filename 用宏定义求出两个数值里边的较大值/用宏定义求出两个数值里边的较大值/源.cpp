#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define MAX(a,b) a>b?a:b

int main()
{
	int x = 0;
	int y = 0;
	printf("������������ֵ\n");
	scanf("%d %d", &x, &y);
	printf("���������нϴ����%d", MAX(x, y));
	getchar();
}