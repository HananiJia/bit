#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m;
	int n;
	int i;
	printf("������m��ֵ\n");
	scanf("%d", &m);
	printf("������n��ֵ\n");
	scanf("%d", &n);
	printf("m=%d,n=%d", m, n);
	printf("������ֵ���н���\n");
	i = m;
	m = n;
	n = i;
	printf("m=%d,n=%d\n", m, n);
	return 0;
}