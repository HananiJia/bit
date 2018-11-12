#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 0;
		int result = numbers[0];//Õ¾¸ÚÊ¿±ø
		int size = numbers.size();
		for (int i = 0; i < size; i++)
		{
			if (numbers[i] == result)
			{
				count++;
			}
			else
			{
				if (count != 0)
				{
					count--;
				}
				else
				{
					result = numbers[i + 1];
				}
			}

		}
		count = 0;
		for (int i = 0; i < size; i++)
		{
			if (numbers[i] == result)
			{
				count++;
			}
		}
		if (count>size / 2)
		{
			return result;
		}
		return 0;
	}
};