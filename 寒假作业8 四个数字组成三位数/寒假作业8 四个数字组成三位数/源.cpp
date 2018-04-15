#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int m = 0;
	for (a = 1; a <= 4; a++)
	{
		for (b = 1; b <= 4; b++)
		{
			for (c = 1; c <= 4; c++)
			{
				m = a * 100 + b * 10 + c;
				printf("%d\n", m);
				
			}
		}
	}
	system("pause");
	return 0;
}