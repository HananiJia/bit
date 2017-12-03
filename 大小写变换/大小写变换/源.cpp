#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m = 0;
	printf("please enter a letter\n");
	m = getchar();
	getchar();
	while (m != EOF)
	{
		
		
		if (m >= 'A' && m <= 'Z')
		{
			m = m + 32;
			printf("%c\n", m);
		}
		
		else if (m >= 'a' && m <= 'z')
		{
				m = m - 32;
				printf("%c\n", m);
		}
	
		else
		{
			printf("data error\n");
		}
		printf("please enter a letter\n");
		m=getchar();
		getchar();
	}

	return 0;
}
