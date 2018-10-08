#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		vector<int> a;
		int n = num;
		while (n >= 1)
		{
			int i = n % 2;
			a.push_back(i);
			n = n / 2;
		}
		int sum = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == 1)
			{
				a[i] = 0;
			}
			else
			{
				a[i] = 1;
			}
			sum = sum + a[i] * pow(2, i);
		}
		
		return sum;
	}
};