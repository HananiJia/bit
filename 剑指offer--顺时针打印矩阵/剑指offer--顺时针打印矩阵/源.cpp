#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> ret;
		int row = matrix.size();//多少个一维数组
		int col = matrix[0].size();//一个数组多少个元素
		if (row == 0 && col == 0)
			return ret;
		int left = 0, right = col - 1, top = 0, bottom = row - 1;
		while (left <= right&&top <= bottom)
		{
			for (int i = left; i <= right; i++)
			{
				ret.push_back(matrix[top][i]);
			}
			for (int i = top+1; i <= bottom; i++)
			{
				ret.push_back(matrix[i][right]);
			}
			if (top != bottom)
			{

				for (int i = right - 1; i >= left; i--)
				{
					ret.push_back(matrix[bottom][i]);
				}
			}
			if (left != right)
			{

				for (int i = bottom - 1; i > top; i--)
				{
					ret.push_back(matrix[i][left]);
				}
			}
			left++;
			right--;
			top++;
			bottom--;
		}
		return ret;
	}
};