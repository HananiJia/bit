#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int sum1 = 0;
	int sum = 0;
	int i = 0;
	int k = 0;
	for (i = 1; i <= 20; i++)
	{
		sum1 = 1;
		for (k = 1; k <= i; k++)
		{
			sum1 = sum1*k;
		}
		printf("%d�Ľ׳�Ϊ%d\n", i, sum1);
		sum = sum + sum1;
	}
	printf("ǰ��ʮ��Ľ׳�Ϊ%d", sum);
	system("pause");
	return 0;
}