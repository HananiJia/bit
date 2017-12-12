#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a[10] = { 2,3,4,5,6,7,8,9,10};
	int i = 0;
	int left = 1;
	int right = sizeof(a) / sizeof(a[0])-1;
	int mid = 0;
	printf("请输入你要查找的数字\n");
	scanf("%d", &i);
	while (left <=right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] > i)
		{
			mid = mid - 1;
			right = mid;
		}
		if (a[mid] < i)
		{
			mid = mid + 1;
			left = mid;
		}
		if (a[mid] == i)
		{
			printf("你查找的是第%d个数\n", mid+1);
			break;
		}
	}
	if (left >= right)
	{
		printf("没有你要查找的数字\n");
	}
	return 0;
	
}