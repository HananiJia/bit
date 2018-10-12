#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int col = A.size();//把A的行数给了col 列
		int row = A[0].size();//把A的列给了row 行
		vector<vector<int>> ret;
		int i = 0;
		int j = 0;
		for (i = 0; i < row; i++)
		{
			vector<int> temp;
			for (j = 0; j < col; j++)
			{
				temp.push_back(A[j][i]);
			}
			ret.push_back(temp);
		}
		return ret;
	}
};