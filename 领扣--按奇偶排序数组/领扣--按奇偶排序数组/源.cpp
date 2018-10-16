#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		vector<int> odd;
		vector<int> even;
		for (int i = 0; i < A.size(); i++)
		{
			if (i % 2 == 0 && A[i] % 2 != 0)
			{
				even.push_back(i);
			}
			if (i % 2 != 0 && A[i] % 2 == 0)
			{
				odd.push_back(i);
			}
		}
		for (int i = 0; i < odd.size(); i++)
		{
			int temp = A[odd[i]];
			A[odd[i]] = A[even[i]];
			A[even[i]] = temp;
		}
		return A;
	}
};