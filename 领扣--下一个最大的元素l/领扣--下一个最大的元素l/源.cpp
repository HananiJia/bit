#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> ret;
		for (int i = 0; i < findNums.size(); i++)
		{
			ret.push_back(FindNum(findNums[i], nums));
		}
		return ret;
	}
	int FindNum(int num, vector<int>& nums)
	{
		int flag = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == num)
			{
				flag = 1;
			}
			if (flag == 1 && nums[i]>num)
				return nums[i];
		}
		return -1;
	}
};
