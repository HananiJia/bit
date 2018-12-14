#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string t;                           //存每次子串的结果
		DFS(t, s, result, 0);
		return result;
	}
	void DFS(string t, string s, vector<string>& result, int count){
		if (count == 3 && isValid(s)){
			result.push_back(t + s);
			return;
		}
		for (int i = 1; i < 4 && i < s.size(); i++){
			string sub = s.substr(0, i);   //取子串
			if (isValid(sub)){
				DFS(t + sub + ".", s.substr(i), result, count + 1);
			}
		}
	}
	bool isValid(string s){
		stringstream ss;
		int num;
		ss << s;
		ss >> num;
		if (s.size() > 1){   //如果数字长度大于1 ，则首位不能是0；
			return s[0] != '0'&&num >= 0 && num < 256;
		}
		return num >= 0 && num, 256;
	}
};
int main()
{
	string a = "25525511135";
	Solution A;
	vector<string> b;
	b=A.restoreIpAddresses(a);
	for (int i = 0; i < b.size(); i++)
	{
		cout << b[i] << endl;
	}
	system("pause");
	return 0;	
}