#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int check()
//{
//	int i = 1;
//	return (*(char*)&i);
//}

int main()
{
	//int a = 20;
	//int b = -10;
	int i = 1;
	int ret = i >> 8;
	//int ret = check();
	if (ret== 0)
		printf("С�˴洢");
	else
		printf("��˴洢");
	//if (ret == 1)
	//	printf("С�˴洢");
	//else
	//	printf("��˴洢");
	return 0;
}