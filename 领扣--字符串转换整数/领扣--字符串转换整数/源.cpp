#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int size = str.size();
		int index = 0;
		int flag = 0;
		while (index < size&&str[index] == ' ')
		{
			index++;
		}
		if (StrIndex(str,index,flag))
			return 0;
		int sum = 0;
		while (StrIndexNum(str, index))
		{
			int n = str[index] - '0';
			int s = sum;
			if (sum>(INT_MAX - n) / 10)
			{
				if (flag == 1)
				{
					return INT_MIN;
				}
				else
				{
					return INT_MAX;
				}
			}
			sum = sum * 10 + n;
			index++;
		}
		if (flag == 1)
			sum = -sum;
		return sum;
	}
	bool StrIndexNum(string str, int index)
	{
		if (str[index] >= '0'&&str[index] <= '9')
			return true;
		return false;
	}
	bool StrIndex(string str, int& index, int& flag)
	{
		if (index >= str.size())
			return true;
		if (str[index] == '-' || str[index] == '+')
		{
			if (str[index] == '-')
			{
				flag = 1;
			}
			index++;
			return false;
		}
		if (str[index] >= '0'&&str[index] <= '9')
			return false;

		return true;

	}
};

int main()
{
	Solution A;
	string a = "-6147483648";
	cout<<A.myAtoi(a)<<endl;
	system("pause");
	return 0;
}