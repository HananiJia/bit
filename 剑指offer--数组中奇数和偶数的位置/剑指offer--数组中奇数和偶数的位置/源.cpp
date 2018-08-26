#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int Find = 0;//寻找奇数
		int Last = 0;//最后一个奇数
		int size = array.size() -1;
		while (Find <size)
		{
			int tmp = 0;
			while (Find<size&&array[Find] % 2 != 1)//
			{
				Find++;
			}
			//开始移动
			if (Find == size&&array[size]%2==0)
				break;
			tmp = array[Find];
			int index = Find;
			while (index > Last+1)
			{
				array[index] = array[index - 1];
				index--;
			}
			array[Last + 1] = tmp;
			Last++;
		}

	}
};


class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0)
			return;
		int length = array.size();
		int Find = 0;
		int Find2 = 0;
		while (Find<length)
		{
			while (Find<length&&array[Find] % 2 != 0)
			{
				Find++;//去找偶数
			}

			Find2 = Find + 1;
			while (Find2<length&&array[Find2] % 2 == 0)
			{
				Find2++;//去找奇数
			}
			if (Find2 < length)
			{
				int tmp = array[Find2];
				for (int find = Find2 - 1; find >= Find; find--)
				{
					array[find + 1] = array[find];
				}
				array[Find++] = tmp;
			}
			else
			{
				break;
			}

		}


	}
};

class Solution {
public:
	void reOrderArray(vector<int> &array) {


		for (int i = 0; i < array.size(); i++)
		{
			for (int j = array.size() - 1; j>i; j--)
			{
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) //前偶后奇交换
				{
					swap(array[j], array[j - 1]);
				}
			}
		}
	}
};


class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int[] narr = new int[array.size()];
	}
};


class Solution{
public:
	void reOrderArray(vector<int> &array) {

		vector<int> array_temp;
		vector<int>::iterator ib1, ie1;
		ib1 = array.begin();


		for (; ib1 != array.end();){            //遇见偶数，就保存到新数组，同时从原数组中删除
			if (*ib1 % 2 == 0) {
				array_temp.push_back(*ib1);
				ib1 = array.erase(ib1);
			}
			else{
				ib1++;
			}

		}
		vector<int>::iterator ib2, ie2;
		ib2 = array_temp.begin();
		ie2 = array_temp.end();

		for (; ib2 != ie2; ib2++)             //将新数组的数添加到老数组
		{
			array.push_back(*ib2);
		}
	}
};