#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid){
		if (grid.empty())
			return 0;
		int count = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					count++;
					FindMaxArea(grid, i, j);
				}
			}
		}
		return count;
	}
	void FindMaxArea(vector<vector<char>>& grid, int i, int j)
	{
		if (grid[i][j] == '1')
		{
			grid[i][j] = '2';
		}
		if (i + 1 < grid.size() && grid[i + 1][j] == '1')
		{
			FindMaxArea(grid, i + 1, j);
		}
		if (j + 1 < grid[i].size() && grid[i][j + 1] == '1')
		{
			FindMaxArea(grid, i, j + 1);
		}
		if (i - 1 >= 0 && grid[i - 1][j] == '1')
		{
			FindMaxArea(grid, i - 1, j);
		}
		if (j - 1 >= 0 && grid[i][j - 1] == '1')
		{
			FindMaxArea(grid, i, j - 1);
		}
		return;
	}
};