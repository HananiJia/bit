#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int  main()
{
	int i;
	int n;
	for (i =101; i <200; i=i+2)
	{
	
		for (n = 2; n <i; n++)
		{
			if (i%n == 0)
			{


				continue;
			}
			


		}
		printf("%d\n", i);
	}
	system("pause");
}
