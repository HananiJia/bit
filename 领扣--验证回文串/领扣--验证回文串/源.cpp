#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//class Solution {
//public:
//	bool isPalindrome(string s) {
//		if (s.size() == 0)
//			return true;
//		int count = 0;
//		int left = 0;
//		int right = s.size() - 1;
//		while (left <= right)
//		{
//			while (left<right&&!isnumorletter(s[left]))
//			{
//				left++;
//			}
//			while (left<right&&!isnumorletter(s[right]))
//			{
//				right--;
//			}
//			togglecase(s[left]);
//			togglecase(s[right]);
//			if (s[left] != s[right] || left >= s.size() || right<0)
//			{
//				return false;
//			}
//			left++;
//			right--;
//			count += 2;
//		}
//		if (count == 0)
//			return false;
//		return true;
//	}
//private:
//	bool isnumorletter(char n)
//	{
//		if (n >= 'A'&&n <= 'Z')
//		{
//			return true;
//		}
//		if (n >= 'a'&&n <= 'z')
//		{
//			return true;
//		}
//		if (n >= '0'&&n <= '9')
//		{
//			return true;
//		}
//		return false;
//	}
//	void togglecase(char& n)
//	{
//		if (n >= 'A'&&n <= 'Z')
//		{
//			n = n + 32;
//		}
//		if (n >= 'a'&&n <= 'z')
//		{
//			n = n - 32;
//		}
//	}
//};
//class Solution {
//public:
//	bool isPalindrome(string s) {
//		if (s.size() == 0)
//			return true;
//		if (s.size() == 1 && s[0] == ' ')
//			return true;
//		string str;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (isnumorletter(s[i]))
//			{
//				togglecase(s[i]);
//				str.push_back(s[i]);
//			}
//		}
//		if (str.size() == 0)
//			return false;
//		int left = 0;
//		int right = str.size()-1;
//		while (left<right)
//		{
//			if (str[left] != str[right])
//			{
//				return false;
//			}
//			left++;
//			right--;
//		}
//		return true;
//	}
//private:
//	bool isnumorletter(char n)
//	{
//		if (n >= 'A'&&n <= 'Z')
//		{
//			return true;
//		}
//		if (n >= 'a'&&n <= 'z')
//		{
//			return true;
//		}
//		if (n >= '0'&&n <= '9')
//		{
//			return true;
//		}
//		return false;
//	}
//	void togglecase(char& n)
//	{
//		if (n >= 'A'&&n <= 'Z')
//		{
//			n = n + 32;
//		}
//		if (n >= 'a'&&n <= 'z')
//		{
//			n = n - 32;
//		}
//	}
//};

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;
		if (s.size() == 1)
			return true;
		string str;
		for (int i = 0; i < s.size(); i++)
		{
			if (isnumorletter(s[i]))
			{
				togglecase(s[i]);
				str.push_back(s[i]);
			}
		}
		if (str.size() == 0)
			return true;
		int left = 0;
		int right = str.size() - 1;
		while (left<right)
		{
			if (str[left] != str[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
private:
	bool isnumorletter(char n)
	{
		if (n >= 'A'&&n <= 'Z')
		{
			return true;
		}
		if (n >= 'a'&&n <= 'z')
		{
			return true;
		}
		if (n >= '0'&&n <= '9')
		{
			return true;
		}
		return false;
	}
	void togglecase(char& n)
	{
		if (n >= 'A'&&n <= 'Z')
		{
			n = n + 32;
		}
		if (n >= 'a'&&n <= 'z')
		{
			n = n - 32;
		}
	}
};

int main()
{
	string str("A man, a plan, a canal: Panama");
	Solution A;
	if (A.isPalindrome(str))
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