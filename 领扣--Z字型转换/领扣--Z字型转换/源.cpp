#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//class Solution {
//public:
//	string convert(string s, int numRows) {
//		if (s.size() <= 1 || numRows == 1)
//			return s;
//		int num = numRows * 2 - 2;
//		int index = 0;
//		int size = s.size();
//		string ret;
//		for (int i = 1; i <= numRows; i++)
//		{
//			index = i - 1;
//			if (i == 1 || i == numRows)
//			{
//				while (index < size)
//				{
//					ret.push_back(s[index]);
//					index += num;
//				}
//			}
//			else
//			{
//				while (index<size)
//				{
//					ret.push_back(s[index]);
//					index += numRows;
//				}
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.size() <= 1 || numRows == 1)
			return s;
		string ret;
		int size = s.size();
		int index = 0;
		vector<string> temp(numRows);
		while (index<size)
		{
			for (int i = 0; i < numRows; i++)
			{
				if (index >=size)
					break;
				temp[i].push_back(s[index]);
				index++;
			}
			for (int i = numRows - 2; i >0; i--)
			{
				if (index >= size)
					break;
				temp[i].push_back(s[index]);
				index++;
			}
		}
		for (int i = 0; i < temp.size(); i++)
		{
			ret += temp[i];
		}
		return ret;
	}
};

int main()
{
	Solution A;
	string a = "PAYPALISHIRING";
	string str = A.convert(a, 4);
	cout << str<< endl;
	system("pause");
	return 0;
}
