#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
1   2  3  4
12 13 14  5
11 16 15  6
10 9   8  7

*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		int size = n*n;
		vector<vector<int>> ret;
		vector<int> temp(n, 0);
		for (int i = 0; i < n; i++)
		{
			ret.push_back(temp);
		}
		Generate(ret, 0, 0, n, 1);
		return ret;
	}
private:
	void Generate(vector<vector<int>> &nums, int row, int col, int m, int num)
	{
		if (m == 0)
			return;
		if (m == 1)
		{

			nums[row][col] = num;
			return;
		}
		for (int i = col; i < m + col; i++)
		{
			nums[row][i] = num;
			num++;
		}
		for (int i = row + 1; i < m + row; i++)
		{
			nums[i][m + row - 1] = num;
			num++;
		}
		for (int i = m + col - 2; i > col; i--)
		{
			nums[m + col - 1][i] = num;
			num++;
		}
		for (int i = m + row - 1; i > row; i--)
		{
			nums[i][col] = num;
			num++;
		}
		Generate(nums, row + 1, col + 1, m - 2, num);
	}
};
//int main()
//{
//	Solution A;
//	vector<vector<int>> ret;
//	ret=A.generateMatrix(4);
//	return 0;
//}

//class Solution {
//public:
//	vector<vector<int>> generateMatrix(int n) {
//		vector<vector<int>> ret(n, vector<int>(n, 0));
//		int num = 1;
//		int sum = n*n;
//		int x = 0;
//		int y = 0;
//		while (num <= sum)
//		{
//			while (y < n&&ret[x][y] == 0)
//			{
//				ret[x][y] = num;
//				num++;
//				y++;
//			}
//			x++;
//			y--;
//			while (x < n&&ret[x][y] == 0)
//			{
//				ret[x][y] = num;
//				num++;
//				x++;
//			}
//			x--;
//			y--;
//			while (y >= 0 && ret[x][y] == 0)
//			{
//				ret[x][y] = num;
//				num++;
//				y--;
//			}
//			y++;
//			x--;
//			while (x > 0 && ret[x][y] == 0)
//			{
//				ret[x][y] = num;
//				num++;
//				x--;
//			}
//			n--;
//			x++;
//			y++;
//		}
//		return ret;
//	}
//};