#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		vector<int> numbers;
		for (int i = 0; i < n; i++)
		{
			numbers.push_back(i);
		}//构建了一个数组数组内容就是每个人的编号
		int nn = n;
		int i = -1;
		int mm = 0;
		while (nn>0)
		{
			i++;
			if (i >= n)
			{
				i = 0;
			}
			if (numbers[i] == -1)
				continue;
			mm++;
			if (mm == m)
			{
				numbers[i] = -1;
				mm = 0;
				nn--;
			}

		}
		return i;		
	}
};

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0) return -1;
		int s = 0;
		for (int i = 2; i <= n; i++){
			s = (s + m) % i;
		}
		return s;
	}
};

class Solution {
public:
	int LastRemaining_Solution(unsigned int n, unsigned int m)
	{
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		else
			return (LastRemaining_Solution(n - 1, m) + m) % n;
	}
};