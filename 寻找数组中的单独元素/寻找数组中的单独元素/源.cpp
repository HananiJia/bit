
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define max 6

int main()
{
	int a[max];
	int i = 0;
	int flag = 0;
	int k = 0;
	for (i = 0; i < max; i++)
	{
		scanf("%d", &a[i]);
		fflush(stdin);
	}
	printf("单独的元素有:\n");
	for (i = 0; i < max; i++)
	{
		flag = 0;
		for (k = 0; k < max; k++)
		{
			if (k == i)
				continue;
			if (a[i] == a[k])
				flag++;
		}
		if (flag == 0)
		
			printf("%d\n", a[i]);
			
	}
	system("pause");
}