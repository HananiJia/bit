#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int n = 0;
	int m = 0;
	for (i = 1; i <= 9; i++)
	{
		for (n = 1; n <= 9; n++)
		{
			m = n*i;
			printf("%d*%d=%d  ", n, i, m);
			
		}
		printf("\n");
	}
	system("pause");
	return 0;
}