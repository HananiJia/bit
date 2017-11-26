#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int a[10];
	int i;
	int max;
	printf("请输入十个数字");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	printf("十个数字分别为");
	for (i = 0; i < 10; i++)
		printf("%d,", a[i]);
	max = a[0];
	for (i = 1; i < 10; i++)
	{

		if (a[i]>max)
			max = a[i];
	}
	printf("\n");
	printf("十个数字中的最大数为%d", max);
	getchar();


}