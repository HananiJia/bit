#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int  main()
{
	char a[100] = { 0 };
	int i = 0;
	int flag = 0;
	int strlen1 = 0;
	printf("请输入一个人字符串以回车结束\n");
	gets(a);
	strlen1 = strlen(a);
	for (i = 0; i < strlen1 / 2; i++)
	{
		if (a[i] != a[strlen1 - i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("该字符串不是回文字符串\n");
	}
	else
	{
		printf("该字符串是回文串\n");
	}
	system("pause");
	return 0;

}