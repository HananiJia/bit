//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	int a[10];
//	//int i, j;
//	printf("请输入十个需要由降序排序的数字:\n");
//	for (int i = 0; i <= 9; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int j = 1; j <= 9; j++)
//	{
//		for (int i = 0; i <= 8; i++)
//		{
//			if (a[i]<a[i + 1])
//			{
//				int q;
//				q = a[i + 1];
//				a[i + 1] = a[i];
//				a[i] = q;
//			}
//		}
//	}
//	/*for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 10 - i - 1; j++)
//		{
//			if (a[j] < a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}*/
//	printf("降序排序的结果是:\n");
//	for (int i = 0; i <= 9; i++)
//		printf("%d ", a[i]);
//	return 0;
//}
////int main()
////{
////	char* str=(char*)malloc(1000);
////	char*str1 = (char*)malloc(1000);
////	//scanf("%s", str);
////	//scanf("%s", str1);
////	gets(str);
////	printf("%s", str);
////	/*printf("%s", str1);*/
////	system("pause");
////	
////}
////int main()
////{
////	printf("请输入十个数字\n");
////	int a[10];
////	for (int i = 0; i <=9; i++)
////	{
////		scanf("%d", &a[i]);
////	}
////	for (int i = 0; i <= 9; i++)
////	{
////		printf("%d", a[i]);
////	}
////	system("pause");
////	return 0;
////}


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i, t;
	printf("下面是100~200内所有素数：\n");
	for (i = 101; i <= 200; i++)
	{
		for (t = 2; t <= i/2; t++)
		{
			if (i%t == 0)
				break;
		}
		if (t>i/2)
		{
			printf("%d,", i);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}


