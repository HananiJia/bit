#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int singleNumber(vector<int>& nums) {
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int flag = 0;
//			for (int j = 0; j < nums.size(); j++)
//			{
//				if (i == j)
//					continue;
//				if (nums[i] == nums[j])
//				{
//					flag = 1;
//					break;
//				}
//			}
//			if (flag == 0)
//			{
//				return nums[i];
//			}
//		}
//	}
//};


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int num = 0;
		for (int i = 1; i <= 32; i++)
		{
			int sum = 0;
			for(int j = 0; j < nums.size(); j++)
			{
				sum += ((nums[j]) >> i) & 1;
			}
			if (sum % 3 == 1)
			{
				num |= 1 << i;
			}
		}
		return num;
	}
};