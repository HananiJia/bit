#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int a = 1;
	int b = 1;
	int c = 0;
	int n = 0;
	int i = 0;
	printf("请输入你想要计算的斐波那契数字个数\n");
	scanf("%d", &n);
	printf("%3d", a);
	printf("%3d", b);
	for (i=2; i < n; i++)
	{
		c = a + b;
		printf("%3d", c);
		a = b;
		b = c;
	}
	system("pause");
	return 0;
}