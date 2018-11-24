#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int findMaxConsecutiveOnes(vector<int>& nums) {
//		int max = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] == 1)
//			{
//				int length = GetOneNum(nums, i);
//				if (length>max)
//					max = length;
//			}
//		}
//		return max;
//	}
//	int GetOneNum(vector<int>& nums, int pos)
//	{
//		int count = 1;
//		int left = pos-1;
//		int right = pos+1;
//		while (left >= 0 && nums[left] == 1)
//		{
//			left--;
//			count++;
//		}
//		while (right < nums.size() && nums[right] == 1)
//		{
//			right++;
//			count++;
//		}
//		return count;
//	}
//};

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int length = 0;
		int max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				length++;
			}
			else
			{
				if (length>max)
					max = length;
				length = 0;
			}
		}
		if (length > max)
			max = length;
		return max;
	}
};