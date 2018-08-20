#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//char a[6] = { 9, 6, 1, 2, 0, 6 };
	char b[10] = { 0 };
	int n = 0;
	while (n<3)
	{
		printf("please enter password\n");
		scanf("%s", b);
		if (strcmp(b, "961206") == 0)
		{
			printf("password correct\n");
			return 0;
			
		}
		else
		{
			n++;
			printf("password error\n");
		}
	}
	printf("Enter password more than three times\n");
}
