#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
	class Solution {
	public:
		bool isHappy(int n) {
			int count = 10;
			while (n != 1)
			{
				n = GetNumSum(n);
				if (n == 4)
					return false;
			}
			return true;
		}
		int GetNumSum(int num)
		{
			int sum = 0;
			while (num > 0)
			{
				int n = num % 10;
				sum += n*n;
				num = num / 10;
			}
			return sum;
		}
	};

int main()
{
	Solution A;
	cout << A.GetNumSum(100) << endl;
	system("pause");
	return 0;
}