#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int coinChange(vector<int>& coins, int amount) {
//		sort(coins.begin(), coins.end());
//		int num = 0;
//		for (int i = coins.size() - 1; i >= 0; i--)
//		{
//			while (amount >= coins[i])
//			{
//				num++;
//				amount -= coins[i];
//			}
//			if (amount == 0)
//				break;
//		}
//		if (amount != 0)
//			return -1;
//		return num;
//	}
//};


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> a(amount + 1, amount + 1);
		a[0] = 0;
		int size = -1;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i - coins[j] >= 0)
				{
					a[i] = min(a[i], a[i - coins[j]] + 1);
				}
			}
		}
		if (a[amount] != amount + 1)
			size = a[amount];
		return size;
	}
};

int main()
{
	Solution A;
	vector<int> a = { 1, 2, 5 };
	cout << A.coinChange(a, 11);
	system("pause");
	return 0;
}