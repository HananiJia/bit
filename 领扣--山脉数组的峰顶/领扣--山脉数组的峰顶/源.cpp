#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int pre = 0;
		int now = 1;
		int next = 2;
		while (1)
		{
			if (A[now] > A[pre] && A[now] > A[next])
				return now;
			else
			{
				pre++;
				now++;
				next++;
			}
		}
		return -1;
	}
};