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
	printf("���һ��1-100֮�������\n");
	scanf("%d", &n);
	while (n != num)
	{


		if (n > num)
		{
			printf("�´��ˣ�����������\n");
		}
		if (n < num)
		{
			printf("��С�ˣ�����������\n");
		}
		scanf("%d", &n);
	}
	printf("�²���ȷ\n");
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


