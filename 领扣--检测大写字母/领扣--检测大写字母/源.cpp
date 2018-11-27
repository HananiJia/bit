#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		int size = word.size();
		if (size == 0)
			return false;
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (word[i] >= 65 && word[i] <= 90)
			{
				count++;
			}
		}
		if (count == 0 || count == size || (count == 1 && word[0] >= 65 && word[0] <= 90&&size!=1))
			return true;
		return false;
	}
};