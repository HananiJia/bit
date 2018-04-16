#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0;
	int m=0;
	int n = 0;
	a = getchar();
	if (a == '}')
		printf("ª®¿®∫≈≤ª∆•≈‰");
	while (a != '\n')
	{
		if (a == '{')
			m++;
		if (a == '}')
			n++;
		a = getchar();
	}
	if (m == n)
		printf("ª®¿®∫≈∆•≈‰");
	else
		printf("ª®¿®∫≈≤ª∆•≈‰");
	
}