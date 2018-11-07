#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {

		return SquenceBST(sequence, 0, sequence.size() - 1);
	}
	bool SquenceBST(const vector<int>& a, int start, int end)
	{
		if (a.empty())
			return false;
		if (start > end)
			return false;
		int middle = a[end];
		int i = start;
		for (; i < end; i++)
		{
			if (a[i]>middle)
			{
				break;
			}
		}
		for (int j = i; j < end; j++)
		{
			if (a[j] < middle)
				return false;
		}
		bool left = true;
		if (i>start)
		{
			left = SquenceBST(a, start, i - 1);
		}
		bool right = true;
		if (i < end - 1)
		{
			right = SquenceBST(a, i, end - 1);
		}
		return  left&&right;
	}
};
