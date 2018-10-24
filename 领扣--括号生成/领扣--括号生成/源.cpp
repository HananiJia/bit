#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
using namespace std;
//
//class Solution {
//public:
//	vector<string> generateParenthesis(int n) {
//		vector<string> ret;
//		set<string> tem;
//		for (int i = 0; i <= n; i++)
//		{
//
//			Parenthesis(tem, i, n - i);
//		}
//		for (auto i:tem)
//		{
//			ret.push_back(i);
//		}
//		return ret;
//	}
//	void Parenthesis(set<string> &tem, int along, int group)
//	{
//		string a;
//		string g;
//		string p = "()";
//		string l = "(";
//		string r = ")";
//		for (int i = 0; i < group; i++)
//		{
//			g = g + p;
//		}
//		for (int i = 0; i < along; i++)
//		{
//			a = a + l;
//		}
//		for (int i = 0; i < along; i++)
//		{
//			a = a + r;
//		}
//		tem.insert(a + g);
//		tem.insert(g + a);
//	}
//};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string s;
		Parenthesis(0, 0, 0, ret, s, n);
		return ret;
 	}
	void Parenthesis(int level, int left, int right, vector<string>& ret,string s, int n)
	{
		if (2*n == level)
		{
			ret.push_back(s);
		}
		if (left < n)
		{
			Parenthesis(level + 1, left + 1, right, ret, s + '(', n);
		}
		if (left>right&&right < n)
		{
			Parenthesis(level + 1, left, right + 1, ret, s + ')', n);
		}

	}
};