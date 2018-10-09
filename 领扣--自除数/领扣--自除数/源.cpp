#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ret;
		for (int i = left; i <= right; i++)
		{
			if (DividingNumbers(i))
			{
				ret.push_back(i);
			}
		}
		return ret;
	}
	bool DividingNumbers(int i)
	{
		if (i >= 1 && i <= 9)
			return true;
		int num = i;
		while (num > 0)
		{
			int n = num % 10;
			if (n==0)
				num = num / 10;
			else
			{
				if (i%n != 0)
					return false;
				num = num / 10;
			}
			
		}
		return true;
	}
};