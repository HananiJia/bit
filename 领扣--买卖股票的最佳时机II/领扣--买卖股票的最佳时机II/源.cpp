#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max = 0;
		int length = prices.size();
		if (length == 0)
			return max;
		for (int i = 1; i < length; i++)
		{
			if (prices[i]>prices[i - 1])
			{
				max += prices[i] - prices[i - 1];
			}
		}
		return max;
	}
};