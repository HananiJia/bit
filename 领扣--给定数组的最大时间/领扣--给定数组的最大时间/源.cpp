#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		sort(A.begin(), A.end());
		string ret = "";
		if (A[0] > 2)//��С�Ķ���2��ֱ�ӷ��ش���
			return ret;
		for (int i = 0; i < 3; i++)
		{
			int max = 0;
			if (A[i]>max)
				max = A[i];
		}

	}
};