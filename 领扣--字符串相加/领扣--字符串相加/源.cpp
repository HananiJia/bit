#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		string ret;
//		int carry = 0;
//		int size1 = num1.size();
//		int size2 = num2.size();
//		int size = size1 > size2 ?size1:size2;
//		rotatestr(num1);
//		rotatestr(num2);
//		for (int i = 0; i < size; i++)
//		{
//			int a = num1[i] - '0';
//			int b = num2[i] - '0';
//			int sum = a + b+carry;
//			if (sum >= 10)
//			{
//				carry = 1;
//				sum -= 10;
//			}
//			char n = sum + '0';
//			ret.push_back(n);
//		}
//		//长的那个要继续运算
//		if ()
//		while (carry)
//		{
//			
//		}
//	}
//	void rotatestr(string& str)
//	{
//		int left = 0;
//		int right = str.size() - 1;
//		while (left < right)
//		{
//			char n = str[left];
//			str[left] = str[right];
//			str[right] = n;
//			left++;
//			right--;
//		}
//	}
//};

//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		int size1 = num1.size();
//		int size2 = num2.size();
//		int size = 0;
//		int carry = 0;
//		if (size1 >= size2)//1更长一点
//		{
//			size = size2;
//			for (int i = size; i >= 0;i--)
//			{
//				int  a = num1[size1] - '0';
//				int  b = num2[size2] - '0';
//				int num = a + b+carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num = num - 10;
//				}
//				num1[size1] = num;
//				size1--;
//				size2--;
//			}
//			while (carry)
//			{
//				int a = num1[size1] - '0';
//				int num = a + carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num = num - 10;
//				}
//				num1[size1] = num;
//				size1--;
//			}
//			return num1;
//		}
//		else{//2更长
//			size = size1;
//			for (int i = size; i >= 0; i--)
//			{
//				int  a = num1[size1] - '0';
//				int  b = num2[size2] - '0';
//				int num = a + b + carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num = num - 10;
//				}
//				num2[size2] = num;
//				size1--;
//				size2--;
//			}
//			while (carry)
//			{
//				int a = num1[size2] - '0';
//				int num = a + carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num = num - 10;
//				}
//				num2[size2] = num;
//				size2--;
//			}
//			return num2;
//		}
//	}
//};

//class Solution {
//public:
//	string addStrings(string num1, string num2) {
//		string ret;
//		int size1 = num1.size();
//		int size2 = num2.size();
//		int carry = 0;
//		int size = size1 > size2 ? size2 : size1;
//		for (int i = size; i > 0;i--)
//		{
//			
//			int a = num1[size1] - '0';
//			int b = num2[size2] - '0';
//			int num = a + b + carry;
//			if (num >= 10)
//			{
//				carry = 1;
//				num -= 10;
//			}
//			else{
//				carry = 0;
//			}
//			ret.push_back(num);
//			size1--;
//			size2--;
//		}
//		if (size1 == 0)//说明1短
//		{
//			while (carry)//进来说明还有进位
//			{
//				int a = num2[size2] + '0';
//				int num = a + carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num -= 10;
//				}
//				else{
//					carry = 0;
//				}
//				ret.push_back(num);
//			}
//			while (size2)
//			{
//				ret.push_back(num2[size2]);
//				size2--;
//			}
//			ret.push_back(num2[0]);
//			return ret;
//		}
//		else//说明2短
//		{
//			while (carry)//进来说明还有进位
//			{
//				int a = num1[size1] + '0';
//				int num = a + carry;
//				if (num >= 10)
//				{
//					carry = 1;
//					num -= 10;
//				}
//				else{
//					carry = 0;
//				}
//				ret.push_back(num);
//			}
//			while (size1)
//			{
//				ret.push_back(num1[size1]);
//				size1--;
//			}
//			ret.push_back(num1[0]);
//			return ret;
//		}
//		
//	}
//};
class Solution {
public:
	string addStrings(string num1, string num2) {
		int size1 = num1.size() - 1;
		int size2 = num2.size() - 1;
		string ret;
		int carry = 0;
		while (size1 >= 0 || size2 >= 0)
		{
			int n1 = 0;
			int n2 = 0;
			if (size1 >= 0)
			{
				n1 = num1[size1] - '0';
				size1--;
			}
			else
			{
				//说明字符串1已经结束了比2短
				n1 = 0;
			}
			if (size2 >= 0)
			{
				n2 = num2[size2] - '0';
				size2--;
			}
			else
			{
				n2 = 0;
			}
			int num = n1 + n2 + carry;
			if (num >= 10)
			{
				carry = 1;
				num -= 10;
			}
			else
			{
				carry = 0;
			}
			ret.push_back(num + '0');
		}
		if (carry != 0)
		{
			ret.push_back('1');
		}
		Rotatestr(ret);
		return ret;
	}
	void Rotatestr(string& str)
	{
		int left = 0;
		int right = str.size() - 1;
		while (left < right)
		{
			char temp = str[left];
			str[left] = str[right];
			str[right] = temp;
			left++;
			right--;
		}
	}
};

int main()
{
	Solution a;
	string num1("1");
	string num2("1");
	a.addStrings(num1, num2);
}