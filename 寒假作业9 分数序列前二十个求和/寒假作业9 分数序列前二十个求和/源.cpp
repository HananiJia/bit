#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	int m = 1;
	int i = 0;
	double sum = 0;
	double k = 0;
	for (n = 1; n <= 20; n++)
	{
		i = m + 1;
		k = i / m;
		m = i;
		sum = sum + k;
	}
	printf("%f", sum);
	system("pause");
	return 0;
}