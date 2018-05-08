#define _CRT_SECURE_NO_WARNINGS 1
/*5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
A选手说：B第二，我第三； 
B选手说：我第二，E第四； 
C选手说：我第一，D第二； 
D选手说：C最后，我第三； 
E选手说：我第四，A第一； 
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 */


#include<stdio.h>
#include<stdlib.h>
int main()
{
	
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int i = 1;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2)  ||  (a == 3)))//A选手说：B第二，我第三； 
						{

							if (((b == 2) ||  (e == 4)))//B选手说：我第二，E第四； 
							{

								if (((c == 1)  ||  (d == 2)))//C选手说：我第一，D第二；
								{

									if (((c == 5)  || (d == 3)))//D选手说：C最后，我第三；
									{

										if (((e == 4)  || (a == 1)))//E选手说：我第四，A第一； 
										{
											if (!((a == b) || (b == c) || (c == d) || (d == e) || (a == c) || (a == d) || (a == e) || (b == d) || (b == e) || (c == e)))
											{
												printf("第%d种情况为:\n", i);
												printf("A为第%d名\n", a);
												printf("B为第%d名\n", b);
												printf("C为第%d名\n", c);
												printf("D为第%d名\n", d);
												printf("E为第%d名\n", e);
												printf("\n");
												i++;
											}
											else continue;


										}
										else continue;

									}
									else continue;

								}
								else continue;

							}
							else continue;

						}
						else continue;

					}

				}

			}

		}


	}
	system("pause");
	
}
//可以有重复