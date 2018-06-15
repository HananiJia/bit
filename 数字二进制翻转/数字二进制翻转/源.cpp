#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value)
{
	unsigned int num = 0;
	int i = 0;
	double k = 0;
	double l = 2.0;
	for (i = 0; i <32; i++)
	{
		k = (value & 1);
		if (k==1)
		num=num+ pow(l, 31 - i);
		value=value >> 1;
	}
	return num;
}

int main()
{
	int n = 0;
	int m = 0;
	printf("请输入一个数字\n");
	scanf("%d", &n);
	m=reverse_bit(n);
	printf("反转二进制之后数字为\n");
	printf("%u", m);
}

//#include<stdio.h>  
//
//#include<math.h>  
//
//#include<stdlib.h>  
//
//typedef  unsigned int unit;
//
//unit reserse_bit(unit value)
//
//{
//
//	int i = 0;
//
//	unit num = 0;
//	double k = 2.0;
//	for (i = 0; i < 32; i++)
//
//	{
//
//		num += ((value >> i) & 1)*pow(k, 31 - i);
//
//	}
//
//	return num;
//
//}
//
//int main()
//
//{
//
//	int value = 0;
//
//	int num = 0;
//
//	scanf("%d", &value);
//
//	num = reserse_bit(value);
//
//	printf("%u\n", num);
//
//	system("pause");
//
//	return 0;
//
//}