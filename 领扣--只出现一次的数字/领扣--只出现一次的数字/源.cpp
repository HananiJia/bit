#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int num=nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			num = num ^ nums[i];
		}
		return num;
	}
};