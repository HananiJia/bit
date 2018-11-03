#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream> 
#include<string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int size = str.size();
		int sum = 0;
		int flag = 1;
		for (int i = 0; i < size; i++)
		{
			if (i==0&&str[i] == '+')
			{
				continue;
			}
			if (i==0&&str[0] == '-')
			{
				flag = 0;
				continue;
			}
			if (str[i] >= 48 && str[i] <= 57)
			{
				int num = str[i] - '0';
				sum += num*pow(10, size - i - 1);
			}
			else
			{
				return 0;
			}
		}
		if (flag == 0)
			return -sum;
		return sum;
	}
};

int main()
{
	Solution A;
	string a("+123");
	int num=A.StrToInt(a);
	cout << num;
	system("pause");
	return 0;
}