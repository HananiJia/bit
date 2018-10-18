#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool hasAlternatingBits(int n) {
		vector<int>temp;
		while (n)
		{
			temp.push_back(n & 1);
			n = n >> 1;
		}
		if (temp.size() <= 1)
			return true;
		for (int i = 0; i < temp.size()-1; i++)
		{
			if (temp[i] == temp[i + 1])
			{
				return false;
			}
		}
		return true;
	}
};