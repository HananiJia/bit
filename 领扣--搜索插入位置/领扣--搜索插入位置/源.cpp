#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;
		int size = nums.size();
		while (i < size&&nums[i] < target)
		{
			i++;
		}
		return i;
	}
};