#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

	class Solution {
	public:
		int minDeletionSize(vector<string>& A) {
			int del = 0;
			if (A.empty()||A.size()==1)
				return del;
			for (int i = 0; i < A[0].size(); i++)
			{
				if (!IsOrOrderStr(A, i))
					del++;
			}
			return del;
		}
		bool IsOrOrderStr(vector<string>& A, int col)
		{
			for (int i = 1; i < A.size(); i++)
			{
				if (A[i][col] < A[i - 1][col])
					return false;
			}
			return true;
		}
	};

int main()
{
	Solution A;
	vector<string> a = { "zyx" };
	cout << A.minDeletionSize(a);
	system("pause");
	return 0;
}