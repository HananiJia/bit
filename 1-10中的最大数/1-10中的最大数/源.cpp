#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int a[10];
	int i;
	int max;
	printf("������ʮ������");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	printf("ʮ�����ֱַ�Ϊ");
	for (i = 0; i < 10; i++)
		printf("%d,", a[i]);
	max = a[0];
	for (i = 1; i < 10; i++)
	{

		if (a[i]>max)
			max = a[i];
	}
	printf("\n");
	printf("ʮ�������е������Ϊ%d", max);
	getchar();


}