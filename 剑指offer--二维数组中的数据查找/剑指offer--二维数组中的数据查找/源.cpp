#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())//如果是空的那么返回真值就进入if条件语句
			return false;//如果进来说明容器中是空的直接返回错误就可以
		int row = 0;//最上边一行
		int col = array[0].size() - 1;//最右边一列
		while (col >= 0 && row < array.size())
		{
			if (target < array[row][col])
				col--;
			else
			{
				if (target>array[row][col])
				{
					row++;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
};