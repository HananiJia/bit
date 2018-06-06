#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void swap(int a[], int n)
{
	int b[MAX] = { 0 };
	int left = 0;
	int right = MAX - 1;
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		if (a[i] % 2 == 0)
		{
			b[left] = a[i];
			left++;
		}
		else
		{
			b[right] = a[i];
			right--;
		}
	}
	for (i = 0; i < MAX; i++)
	{
		a[i] = b[i];
	}
}
int main()
{
	int a[MAX] = { 0 };
	int i = 0;
	for (i = 0; i < MAX; i++)
	{
		printf("请输入第%d个数字\n", i + 1);
		scanf("%d", &a[i]);
	}
	swap(a, MAX);
	printf("交换之后的数组为：\n");
	for (i = 0; i < MAX; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
}