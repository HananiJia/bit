#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int m = 0;
	int n = 0;
	int temp = 0;
	int k = 0;
	printf("��������������\n");
	scanf("%d %d", &m, &n);
	k = m*n;
	if (m < n)
	{
		temp = m;
		m = n;
		n = temp;
	}
	while (m - n != 0)
	{
		temp = m - n;
		if (temp>n)
		{
			m = temp;
		}
		else
		{
			m = n;
			n = temp;
		}

	}
	m = k / m;
	printf("�������ֵ���С��������%d", m);
	system("pause");
	return 0;
}