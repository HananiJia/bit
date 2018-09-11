#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<Windows.h>
using namespace std;

int main()
{

	int i = 0;
	int sum = 0;
	for (i = 0; i < 100; i++)
	{
		cout << i << endl;
		sum += i;

	}
	system("pause");
}

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int start = 0;
		int end = array.size() - 1;
		int product = -1;//用来存储两个数的乘积
		int num1 = 0;
		int num2 = 0;
		while (start < end)
		{
			if ((array[start] + array[end]) == sum)
			{
				if ((array[start] * array[end])<product || product == -1)
				{
					num1 = array[start];
					num2 = array[end];
					product = num1*num2;
				}
				break;
			}
			else
			{
				if ((array[start] + array[end]) > sum)
				{
					end--;
				}
				else
				{
					start++;
				}
			}
			
		}
		vector<int> a;
		if (product == -1)
		   return a;
		else
		{
			a.push_back(num1);
			a.push_back(num2);
			return a;
		}
	}
};

//class Solution {
//public:
//	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//
//		int i = 0;
//		int j = 0;
//		int end = array.size() ;
//		int product = -1;//用来存储两个数的乘积
//		int num1 = 0;
//		int num2 = 0;
//		for (i = 0; i < end; i++)
//		{
//			for (j = i + 1; j < end; j++)
//			{
//				if ((array[i] + array[j]) == sum)
//				{
//					
//					if ((array[i] * array[j])<product||product==-1)
//					{
//						num1 = array[i];
//						num2 = array[j];
//						product = num1*num2;
//					}
//				}
//			}
//		}
//		
//		vector<int> a;
//		if (product == -1)
//			return a;
//		else
//		{
//			a.push_back(num1);
//			a.push_back(num2);
//			return a;
//		}
//		
//	}
//};

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> result;
		int length = array.size();
		int start = 0;
		int end = length - 1;
		while (start < end)
		{
			if (array[start] + array[end] == sum)
			{
				result.push_back(array[start]);
				result.push_back(array[end]);
				break;
			}
			else if (array[start] + array[end] < sum)
				start++;
			else
				end--;
		}
		return result;
	}
};