#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x<0)
//		{
//			return false;
//		}
//		vector<int> num;
//		while (x > 9)
//		{
//			int n= x % 10;
//			num.push_back(n);
//			x = x / 10;
//		}
//		num.push_back(x);
//		int left = 0;
//		int right = num.size() - 1;
//		while (left < right)
//		{
//			if (num[left] != num[right])
//			{
//				return false;
//			}
//			left++;
//			right--;
//		}
//		return true;
//	}
//};


//class Solution {
//public:
//	bool isPalindrome(int x) {
//		if (x < 0 || (x != 0 && x % 10 == 0))
//			return false;
//		int s = 0;
//		while (s <= x) {
//			s = s * 10 + x % 10;
//			if (s == x || s == x / 10)
//				return true;
//			x /= 10;
//		}
//		return false;
//	}
//};

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x != 0 && x % 10 == 0))//当x小于0或者是翻转之后第一位是0的情况都是假
			return false;
		int num = 0;
		while (num <= x)
		{
			num = num * 10 + x % 10;
			if (num == x || num == x / 10)
			{
				return true;
			}
			x = x / 10;
		}
		return false;
	}
};


int main()
{
	Solution A;
	if (A.isPalindrome(1261))
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