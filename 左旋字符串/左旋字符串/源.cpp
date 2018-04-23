#define _CRT_SECURE_NO_WARNINGS 1

//.实现一个函数，可以左旋字符串中的k个字符。 
//ABCD左旋一个字符得到BCDA 
//ABCD左旋两个字符得到CDAB 

#include<stdio.h>
#include<stdlib.h>
void rotate(char *a, int n)
{
	int temp = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		temp = a[0];
		a[0] = a[1];
		a[1] = a[2];
		a[2] = a[3];
		a[3] = temp;
		
	}
}
int main()
{
	char a[5] = { 'A', 'B', 'C', 'D','\0' };
	int n = 0;
	printf("当前数组为:\n");
	printf("%s", a);
	printf("请输入您想要旋转个字符个数:\n");
	scanf("%d", &n);
	rotate(a, n);
	printf("旋转%d个字符之后的字符串为:\n",n);
	printf("%s", a);
	system("pause");
}