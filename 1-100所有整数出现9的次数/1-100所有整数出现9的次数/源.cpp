#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int sum = 1;
	int i = 10;
	int k;
	for (i = 10; i <= 100; i++)
	{
		k = i % 10;
		if (k == 9)
			sum++;
	}
	for (i = 10; i <= 100; i++)
	{
		if (i/10==9)

		sum++;
	}
	printf("%d", sum);
}