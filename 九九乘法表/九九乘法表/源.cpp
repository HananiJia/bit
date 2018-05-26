#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i;
	int m;
	int k;
	for (i = 1; i <= 9; i++)
	{

		for (m = 1; m <= 9; m++)
		{
			k = i*m;
			printf("%d*%d=%d", i, m, k);
			printf("  ");
		}
		printf("\n");
	}
	system("pause");
}