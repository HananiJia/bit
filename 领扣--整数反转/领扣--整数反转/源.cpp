#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		if (x == 0 || x == INT_MIN)
			return 0;
		int flag = 0;
		if (x < 0)
		{
			flag = 1;
			x = -x;
		}
		int sum = 0;
		while (x != 0)
		{
			int num = x % 10;
			sum = sum * 10 + num;
			x = x / 10;
		}
		
		if (flag == 1)
			sum = -sum;
		return sum;
	}
};

int main()
{
	Solution A;
	cout << A.reverse(1230) << endl;
	system("pause");
	return 0;
}