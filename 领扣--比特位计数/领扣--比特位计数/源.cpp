#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//	vector<int> countBits(int num) {
//		int n = num;
//		vector<int> ret;
//		for (int i = 0; i <= num; i++)
//		{
//			ret.push_back(countbit(i));
//		}
//		return ret;
//	}
//	int countbit(int num)
//	{
//		int sum = 0;
//		while (num!=0)
//		{
//			if (num & 1 == 1)
//			{
//				sum++;
//			}
//			num = num >> 1;
//		}
//		return sum;
//	}
//};

//class Solution {
//public:
//	vector<int> countBits(int num) {
//		vector<int> ret;
//		ret.push_back(0);
//		for (int i = 1; i <= num; i++)
//		{
//			ret.push_back(ret[i / 2] + (i & 1));
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ret;
		ret.push_back(0);
		for (int i = 1; i <= num; i++)
		{
			ret.push_back(ret[i&(i-1)]+1);
		}
		return ret;
	}
};