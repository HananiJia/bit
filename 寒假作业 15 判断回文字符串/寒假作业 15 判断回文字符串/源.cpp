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
	printf("������һ�����ַ����Իس�����\n");
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
		printf("���ַ������ǻ����ַ���\n");
	}
	else
	{
		printf("���ַ����ǻ��Ĵ�\n");
	}
	system("pause");
	return 0;

}