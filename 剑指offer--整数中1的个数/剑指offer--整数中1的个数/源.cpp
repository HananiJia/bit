#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n <= 0)
			return 0;
		if (n <= 9)
			return 1;
		int sum = 1;//用来存储1的个数
		int m = 10;
		for (m = 10; m <= n; m++)
		{
			int i = m;
			while (i > 9)
			{
				if (i % 10 == 1)
					sum++;
				i = i / 10;
			}
			if (i == 1)
				sum++;
		}
		return sum;
	}
};