#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m;
	int n;
	printf("请输入m的值");
	scanf("%d", &m);
	printf("请输入n的值");
	scanf("%d", &n);
	printf("m=%d,n=%d\n", m, n);
	m = m + n;
	n = m - n;
	m = m - n;
	printf("交换之后m=%d,n=%d", m, n);
	system("pause");

}