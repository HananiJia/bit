#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int findLUSlength(string a, string b) {
		int asize = a.size();//�ַ���a�ĳ���
		int bsize = b.size();//�ַ���b�ĳ���
		if (asize == 0 || bsize == 0)
			return 0; 
		if (asize == bsize)
		{
			if (a == b)
			{
				return -1;
			}
			else
			{
				return a.size();
			}
		}
		else
		{
			return max(asize, bsize);
		}
	}
};