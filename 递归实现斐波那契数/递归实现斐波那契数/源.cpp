#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


int fib(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}
int main()
{
	int m = 0;
	m = fib(6);
	printf("%d", m);
	system("pause");
}