#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m;
	int n;
	printf("������m��ֵ");
	scanf("%d", &m);
	printf("������n��ֵ");
	scanf("%d", &n);
	printf("m=%d,n=%d\n", m, n);
	m = m + n;
	n = m - n;
	m = m - n;
	printf("����֮��m=%d,n=%d", m, n);
	system("pause");

}