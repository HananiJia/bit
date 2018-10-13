#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int i = 0;
		int j = 0;
		int length = A.size();
		if (length <= 1)
			return 0;
		for (; i < length; i++)
		{
			for (j=0; j < length - i - 1; j++)
			{
				if (A[j + 1]>A[j])
				{
					int temp = A[j + 1];
					A[j + 1] = A[j];
					A[j] = temp; 
				}
			}
		}
		int max = A[0];
		int min = A[length - 1];
		if ((max - min) >= 2*K)
		{
			return max - min - 2 * K;
		}
		else
		{
			return 0;
		}

	}
};


