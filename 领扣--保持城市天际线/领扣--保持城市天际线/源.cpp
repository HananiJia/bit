#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> shu;
		vector<int> heng;
		int max = -1;
		for (int i = 0; i < grid[0].size(); i++)
		{
			max = grid[0][i];
			vector<int> temp;
			for (int j = 0; j < grid.size(); j++)
			{
				temp.push_back(grid[j][i]);
			}
			int max1 = maxvector(temp);
			if (max1>max)
				max = max1;
			shu.push_back(max);
		}
		
		
		for (int i = 0; i < grid.size(); i++)
		{
			max = grid[i][0];
			int max1 = maxvector(grid[i]);
			if (max1>max)
				max = max1;
			heng.push_back(max);
		}
		int sum = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				int min = heng[i]>shu[j] ? shu[j] : heng[i];
				if (grid[i][j] < min)
				{
					sum += min - grid[i][j];
				}
			}
		}
		return sum;

	}
	int maxvector(vector<int> a)
	{
		int max = a[0];
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i]>max)
				max = a[i];
		}
		return max;
	}
};