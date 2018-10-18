#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> numberOfLines(vector<int>& widths, string S) {
		vector<int> ret;
		int length = S.size();
		int row = 0;
		int size = 0;
		for (int i = 0; i < length; i++)
		{
			if (size + widths[S[i] - 97]<100)
				size += widths[S[i] - 97];
			else
			{
				if (size + widths[S[i] - 97] == 100)
				{
					row++;
					size = 0;
				}
				else
				{
					row++;
					size = widths[S[i] - 97];
				}
			}
		}
		if (size != 0)
			row++;
		ret.push_back(row);
		ret.push_back(size);
		return ret;
	}
};