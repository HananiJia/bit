#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		if (words.empty() || words.size() == 1)
			return true;
		for (int i = 1; i<words.size(); i++)
		{
			if (CompareString(words[i-1], words[i], order))
			{
				return false;
			}
		}
		return true;
	}
	bool CompareString(string& a, string& b,string& order)//true代表a大，false代表b大
	{
		int size = 0;
		if (a.size() > b.size())
		{
			size = b.size();
		}
		else
		{
			size = a.size();
		}
		for (int i = 0; i < size; i++)
		{
			size_t posa = order.find(a[i]);
			size_t posb = order.find(b[i]);
			if (posa>posb)
			{
				return true;
			}
			if (posa < posb)
			{
				return false;
			}
		}
		if (a.size()>b.size())
		{
			return true;
		}
		if (a.size() < b.size())
		{
			return false;
		}
		return false;
	}
};

int main()
{
	Solution A;
	vector<string> a = { "apple", "app" };
	string b = "abcdefghijklmnopqrstuvwxyz";
	if (A.isAlienSorted(a, b))
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