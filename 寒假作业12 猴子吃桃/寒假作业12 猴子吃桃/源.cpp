#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m = 1;
	int sum = 1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		sum= (sum + 1) * 2;
	}
	printf("��һ���������%d��", sum);
	system("pause");
	return 0;

}