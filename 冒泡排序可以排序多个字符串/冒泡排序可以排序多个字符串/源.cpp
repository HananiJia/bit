#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void arr_bubble_sort(char(*p)[10])//数组指针，即指向大小为10的数组的指针
{
	int i = 0;
	int j = 0;
	char temp[10];
	char *t = temp;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 - i - 1; j++)
		{
			if (p[j]< p[j + 1])
			{
				t= p[j];
				p[j]=p[j + 1];
			   p[j + 1]= t;
			}
		}
	}
}
int main()
{
	char a[3][10] = { "acdb", "aear", "aube" };
	char i = 0;
	char(*p)[10] = { 0 };
	p = a;//p指向a的第0行
	arr_bubble_sort(p);
	for (i = 0; i < 3; i++)
	{
		printf("%s\n", a[i]);//按行输出
	}
	system("pause");
	return 0;
}