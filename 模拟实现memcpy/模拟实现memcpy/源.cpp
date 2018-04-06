#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
void *my_memcpy(void *det, const void *src, int num)
{
	void *ret = det;
	while (num)
	{
		*(char *)det = *(char *)src;
		det = (char *)det + 1;
		src = (char *)src + 1;
		num--;
	}
	return ret;
}
int main()
{

	float arr1[] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
	float arr2[10];
	int i = 0;
	int len = sizeof(arr1);
	my_memcpy(arr2, arr1, len);
	system("pause");
	return 0;

}
