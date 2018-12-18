#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		if (A.empty()||A.size()==1)
			return 0;
		int row = 0;
		for (int i = 0; i < A[0].size(); i++)
		{
			int n = 0;
			for (int j = 1; j < A.size(); j++)
			{
				if (A[j][i]>=A[j - 1][i])
				{
					n++;
				}
			}
			if (n == A.size() - 1)
			{
				return row;
			}
			else
			{
				row++;
			}
		}
		return row;
	}
};

int main()
{
	Solution A;
	vector<string> a = {"xga", "xfb", "yfa"};
	cout << A.minDeletionSize(a) << endl;
	system("pause");
	return 0;
}