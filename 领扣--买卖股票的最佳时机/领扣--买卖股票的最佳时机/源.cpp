#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int max = 0;
//		for (int i = 0; i < prices.size(); i++)
//		{
//			int length = FindMaxPrice(prices, i);
//			if (length>max)
//				max = length;
//		}
//		return max;
//	}
//	int FindMaxPrice(vector<int>& price, int pos)
//	{
//		int start = price[pos];
//		int max = 0;
//		int length = 0;
//		for (int i = pos + 1; i < price.size(); i++)
//		{
//			length = price[i] - start;
//			if (length>max)
//				max = length;
//		}
//		return max;
//	}
//};
//


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int buy = 0;
		int price = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			buy = min(buy, prices[i]);
			price = max(price, prices[i] - buy);
		}
		return price;
	}
};