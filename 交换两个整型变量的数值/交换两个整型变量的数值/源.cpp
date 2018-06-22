#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m;
	int n;
	int i;
	printf("请输入m的值\n");
	scanf("%d", &m);
	printf("请输入n的值\n");
	scanf("%d", &n);
	printf("m=%d,n=%d", m, n);
	printf("两个数值进行交换\n");
	i = m;
	m = n;
	n = i;
	printf("m=%d,n=%d\n", m, n);
	return 0;
}