#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ret;
		string F = "Fizz";
		string B = "Buzz";
		string FB = "FizzBuff";
		for (int i = 1; i <= n; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				ret.push_back(FB);
			}
			else
			{

				if (i % 3 == 0)
				{
					ret.push_back(F);
				}
				else
				{

					if (i % 5 == 0)
					{
						ret.push_back(B);
					}
					else
					{
						ret.push_back(to_string(i));
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution A;
	vector<string> t;
	t=A.fizzBuzz(15);
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << endl;
	}
	system("pause");
}