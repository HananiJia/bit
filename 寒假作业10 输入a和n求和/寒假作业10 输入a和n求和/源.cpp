#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int k = 0;
	int b = 0;
	printf("请输入想要计算的数字a和计算的个数n\n");
	scanf("%d %d", &a, &n);
	b = a;
	for (i = 0; i < n; i++)
	{
	
		sum = sum + a;
		a = a * 10+b;
	}
	printf("%d", sum);
	system("pause");
	return 0;

}