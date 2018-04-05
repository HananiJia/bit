#define _CRT_SECURE_NO_WARNINGS 1

   #include<stdio.h>
int two(int i)
{

	int count = 0;


	while (i > 0)
	{

		if ((i & 1) == 1)
			count++;
		i = i >> 1;
	}
	return count;
}

	int main()
{
		int n = 0;
		int temp = 0;
		int num = 0;
		printf("please enter a number\n");
		scanf("%d", &n);
		temp = n;
		num= two(n);
		printf("%dÖÐº¬ÓÐ%d¸ö1", temp, num);
		
	}
		


