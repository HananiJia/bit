#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void num(int  i)
{
	double k = i;
	int m = 0;
	int count = 0;
	for (m = 2; m <=sqrt(k); m ++)
	{
		if (i % m == 0)
		{

			printf("%d��������", i);
			break;
		}
		
	}
	if (m > sqrt(k))
	  printf("%d������", i);
}
int main()
{
	double n = 0;
	printf("������һ������\n");
	scanf("%lf", &n);
	num(n);

}