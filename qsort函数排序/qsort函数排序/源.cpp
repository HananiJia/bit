#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  

int cmp1(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);//a>b ������ֵ  
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
	
	qsort(a, 10, sizeof(int), &cmp1);//���ں���ָ�루ָ������ָ�룩��ֱ�Ӵ��뺯�����ͺ���������&  
	//���㶼�ǿ��Եģ���Ϊ�ڵ��ú���ʱҲ��ȡ�ĺ����ĵ�ַ  
	qsort(b, 10, sizeof(char), cmp2);
	
	for (i = 0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i<10; i++)
		printf("%c ", b[i]);
	printf("\n");
	system("pause");
	
}