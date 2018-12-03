#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std; 

class Solution {
public:
	string simplifyPath(string path) {
		stack<string> p;
		vector<string> s;
		int sla = 0;//找斜杠
		int cha = 0;//找字母
		int Size = path.size();
		string ret;
		while (sla < Size&&cha < Size)
		{
			while (sla < Size&&path[sla] == '/')
			{
				sla++;
			}
			if (sla >= Size)
				break;
			cha = sla+1;
			while (cha < Size&&path[cha] != '/')
			{
				cha++;
			}
			string temp = path.substr(sla, cha - sla);
			sla = cha + 1;
			OperationStack(p, temp);
		}
		while (!p.empty())
		{
			s.push_back(p.top());
			p.pop();
		}
		for (int i = s.size() - 1; i >= 0; i--)
		{
			ret += '/';
			ret += s[i];
		}
		if (s.empty())
		{
			ret += '/';
		}
		return ret;
	}
	void OperationStack(stack<string> &s, string temp)
	{
		if (temp == ".")
		{
			return;
			//不操作直接退出
		}
		if (temp == "..")
		{
			if (s.empty())
				return;
			s.pop();
			return;
			//往上退一个
		}
		//两种都不是的话
		s.push(temp);
	}
};

int main()
{
	Solution A;
	string s = "/home//foo/";
	cout << A.simplifyPath(s) << endl;
	system("pause");
	return 0;
}