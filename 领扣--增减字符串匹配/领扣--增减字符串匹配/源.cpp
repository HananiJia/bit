#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//class Solution {
//public:
//	vector<int> diStringMatch(string S) {
//		vector<int> ret;
//		if (S.empty())
//		{
//			return ret;
//		}
//		int num = 0;
//		ret.push_back(num);
//		for (int i = 1; i < S.size(); i++)
//		{
//			if (S[i] == 'I')
//			{
//				num++;
//				ret.push_back(num);
//			}
//			else
//			{
//				num--;
//				ret.push_back(num);
//			}
//		}
//		int min = 0;
//		for (int i = 0; i < ret.size(); i++)
//		{
//			if (ret[i] < min)
//				min = ret[i];
//		}
//		if (min < 0)
//		{
//			for (int i = 0; i < ret.size(); i++)
//			{
//				ret[i] += (0 - min);
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> ret;
		if (S.empty())
			return ret;
		int Dnum = S.size();
		int Inum = 0;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == 'I')
				ret.push_back(Inum++);
			else
				ret.push_back(Dnum--);
		}
		ret.push_back(Dnum);
		return ret;
	}
};
int main()
{
	Solution A;
	string a = "III";
	vector<int> b=A.diStringMatch(a);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i];
	}
	system("pause");
	return 0;
}