#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		vector<int> a(256, -1);
//		int start = -1;
//		int maxlen = 0;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (a[s[i]]>start)
//			{
//				start = a[s[i]];
//			}
//			a[s[i]] = i;
//			maxlen = max(maxlen, i - start);
//		}
//		return maxlen;
//	}
//};

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size())
			return false;
		vector<int> a1(26, 0);		
		for (int i = 0; i < s1.size(); i++)
		{
			a1[s1[i] - 'a']++;
		}
		
		for (int start = 0; start <= s2.size() - s1.size(); start++)
		{
			vector<int> a2(26, 0);
			for (int i = start; i < start+s1.size(); i++)
			{
				a2[s2[i] - 'a']++;
			}
			if (a1 == a2)
				return true;
		}
		return false;
	}
};

int main()
{
	Solution A;
	string s1 = "ab";
	string s2 = "eidboaoo";
	if (A.checkInclusion(s1, s2))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}