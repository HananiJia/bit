#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		int x = 0;
		int y = 0;
		int z = zprojectionArea(grid);
		return x + y + z;
	}
	int xprojectionArea(vector<vector<int>>& grid)
	{
		int x = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			int max = grid[i][0];
			for (int j = 1; j < grid[0].size(); j++)
			{
				if (grid[i][j]>max)
				{
					max = grid[i][j];
				}
			}
			x += max;
		}
		return x;
	}
	int yprojectionArea(vector<vector<int>>& grid)
	{
		int y = 0;
		for (int i = 0; i < grid[0].size(); i++)
		{
			int max = grid[0][i];
			for (int j = 0; j < grid.size(); j++)
			{
				if (grid[j][i]>max)
				{
					max = grid[j][i];
				}
			}
			y += max;
		}
		return y;
	}
	int zprojectionArea(vector<vector<int>>& grid)
	{
		int z = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] != 0)
					z++;
			}
		}
		return z;
	}
};