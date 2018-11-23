#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;

//class Solution {
//public:
//	vector<string> uncommonFromSentences(string A, string B) {
//		map<string, int> ret;
//		vector<string> a;
//		vector<string> b;
//		vector<string> c;
//		SpiltString(a, A);
//		SpiltString(b, B);
//		for (int i = 0; i < a.size(); i++)
//		{
//			ret[a[i]]++;
//		}
//		for (int i = 0; i < b.size(); i++)
//		{
//			ret[b[i]]++;
//		}
//		for (auto k : ret)
//		{
//			if (k.second == 1)
//			{
//				c.push_back(k.first);
//			}
//		}
//		return c;
//	}
//	void SpiltString(vector<string>& a,string b)
//	{
//		int pos = 0;
//		string temp;
//		for (int i = 0; i < b.size(); i++)
//		{
//			if (b[i] == ' ')
//			{
//				temp = b.substr(pos, i - pos);
//				pos = i + 1;
//				a.push_back(temp);
//			}
//		}
//		temp = b.substr(pos);
//		a.push_back(temp);
//	}
//};
class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		map<string, int> ret;
				vector<string> a;
				vector<string> b;
				vector<string> c;
				GetString(a, A);
				GetString(b, B);
				for (int i = 0; i < a.size(); i++)
				{
					ret[a[i]]++;
				}
				for (int i = 0; i < b.size(); i++)
				{
					ret[b[i]]++;
				}
				for (auto k : ret)
				{
					if (k.second == 1)
					{
						c.push_back(k.first);
					}
				}
				return c;
	}
	void GetString(vector<string>& a,string s)
	{
		stringstream inputstream(s);
		string temp;
		while (inputstream >> temp)
		{
			a.push_back(temp);
		}
	}
};

int main()
{
	Solution A;
	string a = "this apple is sweet";
	string b = "this apple is sweet";
	vector<string> m=A.uncommonFromSentences(a,b);
	for (int i = 0; i < m.size(); i++)
	{
		cout << m[i] << endl;
	}
	system("pause");
	return 0;
}