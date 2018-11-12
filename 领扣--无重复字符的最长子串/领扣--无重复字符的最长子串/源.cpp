#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<set>
using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		if (s.size() == 0)
//			return 0;
//		int first = 0;
//		int second = 0;
//		int maxstr = 0;
//		for (; first < s.size(); first++)
//		{
//			string temp;
//			for (int i = first; i < s.size(); i++)
//			{
//				int pos = temp.find(s[i]);
//				if (pos == -1)//˵��û�ҵ�
//				{
//					temp.push_back(s[i]);
//				}
//				else
//				{
//					//˵���ַ������������ַ���				
//					break;
//				}
//			}
//			if (temp.size()>maxstr)
//			{
//				maxstr = temp.size();
//			}
//		}
//		return maxstr;
//	}
//};

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		if (s.empty()) {
//			return 0;
//		}
//		int longest = 1;
//
//		size_t headforfind = 0;
//
//		string substring;
//		for (size_t ii = 0; ii < s.length(); ++ii) {
//			auto posfound = substring.find(s[ii], headforfind);
//			if (posfound != string::npos) {
//				headforfind = posfound + 1;
//			}
//			substring.push_back(s[ii]);
//
//			auto temp = ii - headforfind + 1;
//			if (temp > longest) {
//				longest = temp;
//			}
//		}
//		return longest;
//	}
//};


	class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.empty())
				return 0;
			int first = 0;
			int maxsize = 0;
			string temp;
			for (int i = 0; i < s.size(); i++)
			{
				int pos = temp.find(s[i], first);
				if (pos != -1)//�ҵ��ˣ�˵��temp�����s[i]��
				{
					first = pos + 1;
				}
				temp.push_back(s[i]);//�ҵ��Ҳ����������ȥ����Ϊ�ҵ���֮����ҵ���ʼ�±������
				if ((i - first + 1)>maxsize)
				{
					maxsize = i - first + 1;
				}
			}
			return maxsize;
		}
	};

int main()
{
	Solution A;
	string s = "a";
	cout<<A.lengthOfLongestSubstring(s)<<endl;
	system("pause");
	return 0;
}