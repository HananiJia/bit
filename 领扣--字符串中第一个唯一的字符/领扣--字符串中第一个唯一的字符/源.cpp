#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<map>
using namespace std;

//class Solution {
//public:
//	int firstUniqChar(string s) {
//		int size = s.size();
//		int hashtable[256] = { 0 };
//		for (int i = 0; i < size; i++)
//		{
//			hashtable[s[i]]++;
//		}
//		for (int i = 0; i < size; i++)
//		{
//			if (hashtable[s[i]] == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//};

class Solution {
public:
	int firstUniqChar(string s) {
		map<char, int> ret;
		for (int i = 0; i < s.size(); i++)
		{
			ret[s[i]]++;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (ret[s[i]] == 1)
				return i;
		}
		return -1;
	}
};