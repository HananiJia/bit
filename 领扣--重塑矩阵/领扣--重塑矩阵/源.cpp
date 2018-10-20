#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size();
		int col = nums[0].size();
		if (r*c > row*col)
			return nums;
		int rr = 0;
		int cc = 0;
		vector < vector < int >> ret;
		vector<int> temp;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{ 
				temp.push_back(nums[i][j]);
				if (temp.size() == c)
				{
					ret.push_back(temp);
					temp.resize(0);
				}
			}
		}
		return ret;
	}
};