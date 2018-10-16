#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int sum = 0;
		sort(nums.begin(), nums.end());
		int length = nums.size() / 2;
		int n = 0;
		for (int i = 0; i < length; i++)
		{
			sum += nums[n];
			n = n + 2;
		}
		return sum;
	}
};