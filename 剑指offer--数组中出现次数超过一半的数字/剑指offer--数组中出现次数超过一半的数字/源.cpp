#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();//���������ĳ���
		int i = 0;
		int j = 0;
		for (i = 0; i < length-1; i++)
		{
			for (j = 0; j < length - i - 1; j++)
			{
				if (numbers[j]>numbers[j+1])//���ǰ�ߵıȺ�ߵĴ��Ǿͽ��н���
				{
					int temp = numbers[j];
					numbers[j] = numbers[j+1];
					numbers[j+1] = temp;
				}
			}
		}
		//���������������ˣ���ͬ�����ݿ϶��ǰ�����
		int num = 0;
		i = 0;
		int temp = numbers[i];
		for (i = 0; i < length; i++)
		{
			if (temp == numbers[i])
			{
				num++;
			}
			else
			{
				num = 1;
			}
			if (num>(length / 2))
			{
				return numbers[i];
			}
			temp = numbers[i];
		}
		return 0;
	}
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		int count = 1;
		int i = 0;
		int result = numbers[i];//��һ������Ϊʿ��
		for (i = 0; i < length; i++)
		{
			if (result == numbers[i])
			{
				count++;
			}
			else
			{
				count--;
			}
			if (count == 0)
			{
				result = numbers[i + 1];
			}
		}
		count = 0;
		for (i = 0; i < length; i++)
		{
			if (numbers[i] == result)
				count++;
		}
		if (count>length / 2)
			return result;
		else
			return 0;
	}
};