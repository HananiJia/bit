#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> str;
		if (digits.size() == 0)
		{
			return str;
		}
		string s;
		Combinations(digits, s, 0, str);
		return str;
	}
private:
	void Combinations(string& digits, string& s, int index, vector<string>& str)
	{
		if (index == digits.size())
		{
			str.push_back(s);
			return;
		}
		int num = digits[index] - '0';
		string letter[10] = { " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int i = 0; i < letter[num].size(); i++)
		{
			s.push_back(letter[num][i]);
			Combinations(digits, s, index + 1, str);
			s.pop_back();
		}
		return;
	}
};

int main()
{
	Solution A;
	string a = "23";
	vector<string> ret=A.letterCombinations(a);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << endl;
	}

	system("pause");
	return 0;
}