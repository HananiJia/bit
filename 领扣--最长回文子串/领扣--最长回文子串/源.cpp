#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;


//class Solution {
//public:
//	string longestPalindrome(string s) {
//		if (s.size() == 0 || s.size() == 1)
//			return s;
//		if (isHuiWen(s))
//		{
//			return s;
//		}
//		int maxlong = 0;
//		string ret;
//		for (int i = 0; i < s.size(); i++)
//		{
//			for (int j = i; j < s.size(); j++)
//			{
//				if (s[i] == s[j])
//				{
//					int len = 0;
//					if (j == 0)
//					{
//						len = 1;
//					}
//					else
//					{
//						len = j - i;
//					}
//					string temp = s.substr(i, len+1);
//					if (isHuiWen(temp))//是回文
//					{
//						int sizelong = j - i;
//						if (sizelong>=maxlong)
//						{
//							maxlong = sizelong;
//							ret = temp;
//						}
//					}
//				}
//			}
//		}
//		return ret;
//	}
//	bool isHuiWen(string s)
//	{
//		int start = 0;
//		int end = s.size()-1;
//		while (start <= end)
//		{
//			if (s[start] != s[end])
//			{
//				return false;
//			}
//			start++;
//			end--;
//		}
//		return true;
//	}
//};

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
		{
			return s;
		}
		string ret;
		int maxlen = 0;
		for (int i = 0; i < s.size() - 1; i++)
		{
			LongestPalinadrome(s, ret, i, i, maxlen);//bab
			LongestPalinadrome(s, ret, i, i + 1, maxlen);//baab
			//两种情况所以需要传左是i右是i的也要有左是右是i+1
		}
		return ret;
	}
	void LongestPalinadrome(string& s, string& ret, int left, int right, int& max)
	{
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}
		//起始点为left+1
		//长度是right-left-1
		int len = right - left - 1;
		if (len>max)
		{
			max = len; 
			ret = s.substr(left + 1, len);
		}
		
	}
};

int main()
{
	Solution A;
	string s = "babad";
	cout << A.longestPalindrome(s) << endl;
	system("pause");
	return 0;

}