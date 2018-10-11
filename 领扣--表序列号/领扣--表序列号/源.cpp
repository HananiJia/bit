#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Solution {
public:
	int titleToNumber(string s) {
		int length = s.size();
		int i = 0;
		int sum = 0;
		int m = length - 1;
		while (i<length)
		{
			sum += (s[i] - 64)*pow(26, m);
			m--;
			i++;
		}
		return sum;
	}
};