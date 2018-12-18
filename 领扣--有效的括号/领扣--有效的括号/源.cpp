#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.empty())
			return true;
		stack<char> a;
		map<char, char> b = { { '(', ')' }, { '[', ']' }, { '{', '}'} };
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				a.push(s[i]);
			}
			else
			{
				if (a.empty()||b[a.top()] != s[i])
				{
					return false;
				}
				a.pop();
			}
		}
		if (!a.empty())
			return false;
		return true;
	}
};