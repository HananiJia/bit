#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> array;
		int left = 1;
		int right = 1;
		int n = 1;//两个数之和
		while (left <= right)
		{
			right++;
			n = n + right;
			while (n > sum)
			{
				n = n - left;
				left++;
			}
			if ((sum == n) && left != right)
			{
				vector<int> tmp;
				int l = left;
				for (l = left; l <= right; l++)
				{
					tmp.push_back(l);
				}
				array.push_back(tmp);
			}
		}
		return array;
	}
};





//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i, j, k;
//	int a[10];
//	printf("input 10 numbers:\n");
//	for (i = 0; i < 10; i++)
//		scanf("%d", &a[i]);
//	printf("\n");
//	for (j = 0; j<10; j++)
//	for (i = j; i<10-j-1; i++)
//	if (a[i] > a[i + 1])
//	{
//		int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t;
//	}
//	for (i = 0; i < 10; i++)
//	{
//
//		printf("%d", a[i]);
//	}
//	system("pause");
//	return 0;
//}

