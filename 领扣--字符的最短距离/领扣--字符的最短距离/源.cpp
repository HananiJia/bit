#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> pos;
		vector<int> ret;
		int length = S.size();
		for (int i = 0; i < length; i++)
		{
			if (S[i] == C)
			{
				pos.push_back(i);
			}
		}
		for (int i = 0; i < length; i++)
		{
			ret.push_back(MinPoslong(i, pos));
		}
		return ret;

	}
	int MinPoslong(int n, vector<int> &a)
	{
		int min = -1;
		int temp = 0;
		for (int i; i < a.size(); i++)
		{
			if (a[i]>n)
			{
				temp = a[i] - n;
			}
			else
			{
				temp = n - a[i];
			}
			if (min > temp)
			{
				min = temp;
			}
		}
		return min;
	}
};