#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string ReverseSentence(string str) {
		int left = 0;
		int right = str.size() - 1;
		while (left < right)
		{
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
			//student. a am I
			//i ma a .tneduts
		}
		int i = 0;
		while (i<str.size())
		{
			while (i < str.size() && str[i] == ' ')
				i++;
			//�ҵ��˵�һ�����ǿո��λ��
			left = right = i;
			while (i < str.size() && str[i] != ' ')
			{
				i++;
				right++;
			}
			//�ҵ��ո��λ��
			Reverseword(str, left, right - 1);			
		}
		return str;
	}	
	void Reverseword(string &str, int left, int right)
	{
		while (left < right)
		{
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
		}	
	}
};