#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#define M 4//M�����ά���������
#define N 4//N�����ά���������


int main()
{
	int a[M][N] = { 0 };
	int m = 0;
	int n = 0;
	int i = 0;
	printf("������һ�����ж��ǵ����Ķ�ά����\n");
	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
		{
			printf("�������%d�е�%d�е�Ԫ��:\n", m + 1, n + 1);
			scanf("%d", &a[m][n]);
		}
	}
	for (m = 0; m < M; m++)
	{
		for (n = 0; n < N; n++)
		{
			printf("�������%d�е�%d�е�Ԫ��Ϊ%d:\n", m + 1, n + 1,a[m][n]);
			
		}
	}
	printf("����������Ҫ���ҵ�����:\n");
	scanf("%d", &i);
	if ((a[0][0]>i) || a[M-1][N-1] < i)
	{
		printf("������û�и�����\n");
		return 0;
	}
	if (a[0][0] == i)
	{
		printf("��������ڸ�����\n");
		return 0;
	}
	n = 0;
	m = 0;
	if (a[0][N-1] >= i)
	{
		for (n = N-1; n > 0; n--)
		{
			if (a[m][n] == i)
			{
				printf("��������ڸ�����\n");
				return 0;
			}
			

		}
	
		printf("������û�и�����\n");
		return 0;
	
	}
	
	if (a[0][N-1] < i)
	{
		m = M-1;
		for (n = 0; n < N; n++)
		{

			if (a[m][n] == i)
			{
				printf("��������ڸ�����\n");
				return 0;
			}
			
		}
	
		printf("������û�и�����\n");
		return 0;
	

	}
	system("pause");
}