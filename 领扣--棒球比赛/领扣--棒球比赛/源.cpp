#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class Solution {
//public:
//	int calPoints(vector<string>& ops) {
//		int first = 0;
//		int second = 0;
//		int sum = 0;
//		sum += Calpoints(ops[0], first, second);
//		first= Calpoints(ops[1], first, second);
//		sum += first;
//		second = sum;
//		for (int i = 2; i < ops.size(); i++)
//		{
//			int now = Calpoints(ops[i], first, second);
//			second = first + now;
//			first = now;
//			sum += now;
//		}
//		return sum;
//	}
//	int Calpoints(string s, int first, int second)
//	{
//		char a = s[0];
//		if (a >= 30 && a <= 39)
//		{
//			return a - 30;
//		}
//		if (a == '+')
//		{
//			return second;
//		}
//		if (a == 'D')
//		{
//			return 2 * first;
//		}
//		if (a == 'C')
//		{
//			return -first;
//		}
//	}
//};

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> ret;
		int sum = 0;
		for (int i = 0; i < ops.size(); i++)
		{
			if (ops[i] == "D")
			{
				int num = ret[ret.size() - 1]*2;
				ret.push_back(num);
			}
			else
			{
				if (ops[i] == "C")
				{
					ret.pop_back();
				}
				else
				{
					if (ops[i] == "+")
					{
						int num = ret[ret.size() - 1] + ret[ret.size() - 2];
						ret.push_back(num);
					}
					else
					{
						ret.push_back(stoi(ops[i]));
					}
				}
			}
		}
		for (int i = 0; i < ret.size(); i++)
		{
			sum += ret[i];
		}
		return sum;
	}
};