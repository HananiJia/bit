#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		int start = 0;
		int end = 0;
		int i = 0;
		while (i < s.size())
		{
			while (i < s.size() && s[i] == ' ')
			{
				i++;
			}
			end = start = i;
			while (i < s.size() && s[i] != ' ')
			{
				i++;
				end++;
			}
			reverse(s, start, end - 1);
		}
		return s;
	}
	void reverse(string& s,int start,int end)
	{
		while (start <= end)
		{
			char temp = s[start];
			s[start] = s[end];
			s[end] = temp;
			start++;
			end--;
		}
	}
};