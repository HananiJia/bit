#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  

int cmp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);//a>b 返回正值  
}

int cmp2(const void * a, const void *b)
{
	return(*(char*)a - *(char*)b);
}


void main(void)
{
	int i;
	int a[10] = { 9, 1, 3, 2, 7, 5, 6, 4, 8, 0 };
	char b[10] = { 'i', 'g', 'c', 'e', 'd', 'f', 'b', 'h', 'a', 'j' };
	
	qsort(a, 10, sizeof(int), &cmp1);//对于函数指针（指向函数的指针），直接传入函数名和函数名进行&  
	//运算都是可以的，因为在调用函数时也是取的函数的地址  
	qsort(b, 10, sizeof(char), cmp2);
	
	for (i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i<10; i++)
		printf("%c ", b[i]);
	printf("\n");
	system("pause");
	
}