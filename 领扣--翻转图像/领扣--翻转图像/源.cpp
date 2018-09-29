#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int i = 0;
		int j = 0;
		int len1 = A.size();
		int len2 = A[i].size();
		while (i < len1)
		{
			int left = 0;
			int right = len2-1;
			while (left < right)
			{
				int temp = A[i][left];
				A[i][left] = A[i][right];
				A[i][right] = temp;
				left ++;
				right--;
			}
			
			i++;
		}
		for (int n = 0; n < len1; n++)
		{
			for (int m = 0; m < len2; m++)
			{

				if (A[n][m] == 0)
				{
					A[n][m] = 1;
				}
				else
				{
					A[n][m] = 0;
				}
			}
		}
		return A;
	}
};