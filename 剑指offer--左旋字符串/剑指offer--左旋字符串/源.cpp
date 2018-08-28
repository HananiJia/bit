#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string>


class Solution {
public:
	string LeftRotateString(string str, int n) {
		int size = str.size()-1;//获得字符串的长度
		char temp;
		int i = 1;
		for(i=1; i <= n; i++)
		{
			temp = str[0];
			for (int m = 0; m < size; m++)
			{
				str[m] = str[m + 1];
			}
			str[size] = temp;
		}
		return str;
		
	}
};

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (n<0) return NULL;
		if (n == 0) return str;
		string strTemp = "";

		strTemp = str.substr(0, n);
		str.erase(0, n);
		str += strTemp;
		return str;

	}
};