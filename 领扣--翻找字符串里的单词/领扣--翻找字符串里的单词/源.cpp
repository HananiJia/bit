#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		int bl=0;//Ѱ�ҿո�
		int ch=0;//Ѱ����ĸ
		int size = s.size();
		vector<string> str;
		string temp;
		while (bl < size&&ch < size)
		{
			while (bl < size&&s[bl] == ' ')
			{
				bl++;
			}
			if (bl == size)
				break;
			//����ѭ���������ҵ��˲��ǿո��λ��
			ch = bl+1 ;
			while (ch < size&&s[ch] != ' ')
			{
				ch++;
			}
			//����ѭ���������ҵ��˿ո�
			str.push_back(s.substr(bl, ch - bl));
			bl = ch+1;
		}
		for (int i = str.size() - 1; i >= 0; i--)
		{
			temp += str[i];
			if (i != 0)
				temp += " ";
		}
		s = temp;
		return;
	}
};

int main()
{
	Solution A;
	string s = "  1  ";
	A.reverseWords(s);
	cout << s;
	system("pause");
	return 0;
}