#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

//class Solution {
//public:
//	string intToRoman(int num) {
//		int bit = 0;
//		int index = 0;
//		string ret;
//		while (num > 0)
//		{
//			int n = num % 10;
//			bit++;
//			ret += IntToRoman(n, bit);
//			num = num / 10;
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//	string IntToRoman(int num, int bit)
//	{
//		string ret;
//		if (bit == 1)
//		{
//			if (num < 4)
//			{
//				for (int i = 1; i <= num; i++)
//				{
//					ret += "I";
//				}
//			}
//			else
//			{
//				if (num == 4)
//				{
//					ret += "IV";
//				}
//				else
//				{
//
//					if (num == 9)
//					{
//						ret += "IX";
//					}
//					else
//					{//5-8
//						ret += "V";
//						for (int i = 0; i <= num - 5; i++)
//						{
//							ret += "I";
//						}
//					}
//				}
//			}
//				return ret;	
//		}
//		if (bit == 2)
//		{
//			if (num <= 3)
//			{
//
//				for (int i = 1; i <= num; i++)
//				{
//					ret += "X";
//				}
//			}
//			else
//			{
//
//				if (num == 4)
//				{
//					ret += "XL";
//				}
//				else
//				{
//
//					if (num == 9)
//					{
//						ret += "XC";
//					}
//					else
//					{
//						for (int i = 0; i <= num - 5; i++)
//						{
//							ret += "X";
//						}
//					}
//				}
//			}
//			return ret;
//
//		}
//		if (bit == 3)
//		{
//			if (num <= 3)
//			{
//				for (int i = 1; i <= num; i++)
//				{
//					ret += "C";
//				}
//			}
//			else
//			{
//
//				if (num == 4)
//				{
//					ret += "CD";
//				}
//				else
//				{
//
//					if (num == 9)
//					{
//						ret += "CM";
//					}
//					else
//					{
//						for (int i = 0; i <= num - 5; i++)
//						{
//							ret += "M";
//						}
//					}
//				}
//			}
//			return ret;
//		}
//		else
//		{
//			if (num < 4)
//			{
//				for (int i = 1; i <= num; i++)
//				{
//					ret += "M";
//				}
//			}
//		}
//		return ret;
//	}
//};


class Solution {
public:
	string intToRoman(int num) {
		//map<int, string> a = { { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" }, { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" }, { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" } };
		vector<string> b = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
		vector<int> a = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string ret;
		int n = 0;
		for (int i = 0; i < a.size(); i++)
		{
			while (num >= a[i])
			{
				num -= a[i];
				ret += b[i];
			}
		}
		return ret;
	}
};

int main()
{
	Solution A;	

	cout<<A.intToRoman(3)<<endl;
	cout << A.intToRoman(4) << endl;
	cout << A.intToRoman(9) << endl;
	cout << A.intToRoman(58) << endl;
	cout << A.intToRoman(1944) << endl;
	cout << A.intToRoman(3999) << endl;
	system("pause");
	return 0;
}