#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (haystack.size() < needle.size())
			return -1;
		for (int i = 0; i <= haystack.size() - needle.size(); i++)
		{
			int index = i;
			int index2 = 0;
			while (haystack[index] == needle[index2])
			{
				index++;
				index2++;
				if (index2 == needle.size())
					break;
			}
			if (index2 == needle.size())
				return i;
		}
		return -1;
	}
};