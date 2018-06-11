#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define M 4//M代表二维数组的行数
#define N 4//N代表二维数组的列数


int main()
{
	int a[M][N] = { 0 };
	int m = 0;
	int n = 0;
	int i = 0;
	printf("请输入一个行列都是递增的二维数组\n");
	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
		{
			printf("请输入第%d行第%d列的元素:\n", m + 1, n + 1);
			scanf("%d", &a[m][n]);
		}
	}
	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
		{
			printf("请输入第%d行第%d列的元素为%d:\n", m + 1, n + 1,a[m][n]);
			
		}
	}
	printf("请输入您想要查找的数字:\n");
	scanf("%d", &i);
	if ((a[0][0]>i) || a[M-1][N-1] < i)
	{
		printf("该数组没有该数字\n");
		return 0;
	}
	if (a[0][0] == i)
	{
		printf("该数组存在该数字\n");
		return 0;
	}
	n = 0;
	m = 0;
	if (a[0][N-1] >= i)
	{
		for (n = N-1; n > 0; n--)
		{
			if (a[m][n] == i)
			{
				printf("该数组存在该数字\n");
				return 0;
			}
			

		}
	
		printf("该数组没有该数字\n");
		return 0;
	
	}
	
	if (a[0][N-1] < i)
	{
		m = M-1;
		for (n = 0; n < N; n++)
		{

			if (a[m][n] == i)
			{
				printf("该数组存在该数字\n");
				return 0;
			}
			
		}
	
		printf("该数组没有该数字\n");
		return 0;
	

	}
	system("pause");
}