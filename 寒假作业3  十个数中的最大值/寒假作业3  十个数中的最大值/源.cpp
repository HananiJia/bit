#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int max = 0;
	int a[10] = { 0 };
	int i = 0;
	printf("请依次输入十个整数\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
		if (a[i]>max)
			max = a[i];
	}
	printf("%d", max);
	system("pause");
	return 0;

}