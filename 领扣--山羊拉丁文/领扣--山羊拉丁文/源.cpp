#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string toGoatLatin(string S) {
		if (S.empty())
			return S;
		vector<string> ret;
		string m;
		SplitString(ret, S);
		for (int i = 0; i < ret.size(); i++)
		{
			Operatorstring(ret[i], i + 1);
			m += ret[i];
			if (i < ret.size()-1)
			   m += ' ';
		}
		return m;
	}
	void SplitString(vector<string>& a,string s)
	{
		int pos = 0;
		int value = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ')
			{
				value = i - pos;
				a.push_back(s.substr(pos, value));
				pos = i+1;
			}
		}
		value = s.size() - pos;
		a.push_back(s.substr(pos, value));
	}
	void Operatorstring(string& a,int n)
	{
		string temp = { 'a', 'e', 'i', 'o', 'u' ,'A','E','I','O','U'};
		size_t pos = temp.find(a[0]);
		if (pos <= 9)
		{
			a += "ma";
		}
		else
		{
			a.push_back(a[0]);
			a = a.substr(1, a.size() - 1);
			a += "ma";
		}
		for (int i = 1; i <= n; i++)
		{
			a.push_back('a');
		}
	}
};

int main()
{
	Solution A;
	string s("The quick brown fox jumped over the lazy dog");
	cout<<A.toGoatLatin(s)<<endl;
	system("pause");
	return 0;
}