#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int num = 0;
	printf("请输入两个数字\n");
	scanf("%d %d", &a, &b);
	/*if (a > b)
	{
		a = a - b;
		num = b + a / 2;
	}
	else
	{
		b = b - a;
		num = a + b / 2;
	}*/


	//num = (a + b) >> 1;

	//num = (a&b) + (a^b) / 2;
	printf("%d", num);
	system("pause");
}