#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<map>
using namespace std;
//class Solution {
//public:
//	int romanToInt(string s) {
//		int num = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			int flag = 0;
//			num += BacnNum(s, i, flag);
//			if (flag == 1)
//				i++;
//		}
//		return num;
//	}
//	int BacnNum(string s, int pos,int& flag)
//	{
//		if (pos + 1 < s.size())
//		{
//
//			if (s[pos] == 'I'&&s[pos + 1] == 'V')
//			{
//				flag = 1;
//				return 4;
//			}
//			if (s[pos] == 'I'&&s[pos + 1] == 'X')
//			{
//				flag = 1;
//				return 9;
//			}
//			if (s[pos] == 'X'&&s[pos + 1] == 'L')
//			{
//				flag = 1;
//				return 40;
//			}
//			if (s[pos] == 'X'&&s[pos + 1] == 'C')
//			{
//				flag = 1;
//				return 90;
//			}
//			if (s[pos] == 'C'&&s[pos + 1] == 'D')
//			{
//				flag = 1;
//				return 400;
//			}
//			if (s[pos] == 'C'&&s[pos + 1] == 'M')
//			{
//				flag = 1;
//				return 900;
//			}
//		}
//		if (s[pos] == 'I')
//		{
//			return 1;
//		}
//		if (s[pos] == 'V')
//		{
//			return 5;
//		}
//		if (s[pos] == 'X')
//		{
//			return 10;
//		}
//		if (s[pos] == 'L')
//		{
//			return 50;
//		}
//		if (s[pos] == 'C')
//		{
//			return 100;
//		}
//		if (s[pos] == 'D')
//		{
//			return 500;
//		}
//		if (s[pos] == 'M')
//		{
//			return 1000;
//		}
//	}
//};

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> t = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 500 } };
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int num = t[s[i]];
			if (i == s.size() - 1 || t[s[i]]>t[s[i + 1]])
				sum += num;
			else
				sum -= num;
		}
		return sum;
	}
};