#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		int col = A.size();//��A����������col ��
		int row = A[0].size();//��A���и���row ��
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