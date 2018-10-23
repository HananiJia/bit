#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[6] = { 5, 4, 3, 2, 1,6 };
	int b[6] = { 100, 99, 98, 97, 96 ,95};
	int i, j;
	printf("a数组的值为：\n");
	for (i = 0; i<6; i++)
		printf("%d ", a[i]);
	printf("\nb数组的值为：\n");
	for (j = 0; j<6; j++)
		printf("%d ", b[j]);
	for (i = 0; i <= 5; i++)
	{
				int k;
				k = a[i];
				a[i] = b[i];
				b[i] = k;		
	}
	printf("\n");
	printf("\n交换后的结果：\n");
	printf("a数组的值：\n");
	for (i = 0; i<6; i++)
		printf("%d ", a[i]);
	printf("\nb数组的值：\n");
	for (j = 0; j<6; j++)
		printf("%d ", b[j]);
	system("pause");
	return 0;
}