#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		map<string, int> visits;//����һ��map��������Ϊstring��ֵ����Ϊint
		char *spot = ".";
		for (int i = 0; i < cpdomains.size(); i++)
		{
			int pos = cpdomains[i].find(" ");//���ؿո��λ��
			int num = stoi(cpdomains[i].substr(0, pos));//stoi��ǰ�ߵ��ַ������ֱ��int����
			int length = cpdomains[i].size();
			string temp = cpdomains[i].substr(pos + 1, length - pos - 1);//��ȥ�����ֵ��ַ���������
			//���ű�������ַ�������.����λ��
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
		//	ret.push_back(to_string(k.second) + " " + k.first);//��map�зֿ��������ٴ���ϵ�һ����뵽ret��ߡ�
		//}
		return ret;
		
	}
};