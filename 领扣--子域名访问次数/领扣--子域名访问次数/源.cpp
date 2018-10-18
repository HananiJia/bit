#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		map<string, int> visits;//创建一个map数据类型为string键值类型为int
		char *spot = ".";
		for (int i = 0; i < cpdomains.size(); i++)
		{
			int pos = cpdomains[i].find(" ");//返回空格的位置
			int num = stoi(cpdomains[i].substr(0, pos));//stoi把前边的字符串数字变成int数字
			int length = cpdomains[i].size();
			string temp = cpdomains[i].substr(pos + 1, length - pos - 1);//把去掉数字的字符串存起来
			//倒着遍历这个字符串遇到.返回位置
			for (int n = temp.size() - 1; n >= 0; n--)
			{
				if (temp[n] == *spot)
				{
					visits[temp.substr(n + 1, temp.size() - 1)] += num;
				}
				else
				{
					if (n == 0)
					{
						visits[temp] += num;
					}
				}
			}
		}
		map<string, int> ::iterator iter = visits.begin();
		vector<string> ret;
		for (iter = visits.begin(); iter != visits.end(); iter++)
		{
			ret.push_back(to_string(iter->second) + " " + iter->first);
		}
		//for (auto k : visits)
		//{
		//	ret.push_back(to_string(k.second) + " " + k.first);//把map中分开的类型再次组合到一起插入到ret里边。
		//}
		return ret;
		
	}
};