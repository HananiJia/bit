#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("******************************\n");
	printf("1.play game         2.exit    \n");
	printf("******************************\n");
}
void game()
{
	int num = 0;
	int n = 0;
	srand((int)time(NULL));
	num = rand() % 100 + 1;
	printf("请猜一个1-100之间的数字\n");
	scanf("%d", &n);
	while (n != num)
	{


		if (n > num)
		{
			printf("猜大了，请重新输入\n");
		}
		if (n < num)
		{
			printf("猜小了，请重新输入\n");
		}
		scanf("%d", &n);
	}
	printf("猜测正确\n");
}

int main()
{
	
	int o;
	
		menu(); 
		scanf("%d", &o);
		switch (o)
		{

		case 1: game(); break;
		case 2: return 0;
		}
		
		
		


	
}


