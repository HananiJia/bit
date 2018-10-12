#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class Solution {
public:
	int addDigits(int num) {
		int sum = 0;
		int temp = num;
		while (temp > 9)
		{
			int n = temp % 10;
			sum += n;
			temp = temp / 10;
		}
		if (sum <= 9)
		{
			return sum;
		}
		else
		{
			sum = addDigits(sum);
			return sum;
		}
	}
};