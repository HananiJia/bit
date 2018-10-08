#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string reverseString(string s) {
		int left = 0;
		int right = s.size() - 1;
		while (left <= right)
		{
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
		return s;
	}
};