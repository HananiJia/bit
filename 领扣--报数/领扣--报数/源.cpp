#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string ret = "1";
		string temp = "";
		for (int i = 1; i < n; i++)
		{
			int t = 0;
			while (t < ret.size())
			{
				int value = 0;
				while (t<ret.size()-1&&ret[t] == ret[t + 1])
				{
					t++;
					value++;
				}
				temp += to_string(value) + ret[t];
				t++;

			}
			ret = temp;
			temp = "";
		}
		return ret;
	}
};