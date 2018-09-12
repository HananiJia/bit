#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vextor>

using namespace std;


//public static int find1From2(int[] a){
//	int len = a.length, res = 0;
//	for (int i = 0; i < len; i++){
//		res = res ^ a[i];
//	}
//	return res;
//}


class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int len = data.size();
		int ret = 0;
		int count = 0;
		int i = 0;
		for (i = 0; i < len; i++)
		{
			ret = ret^data[i];
		}
		for (count = 0; count < 32; count++)
		{
			if ((ret & 1))
			{
				break;
			}
			else
				ret = ret >> 1;
		
		}
		*num1 = 0;
		*num2 = 0;
		for (i = 0; i < len; i++)
		{
			
			if (((data[i]>>count)&1))
			{
				*num1 ^= data[i];
			}
			else
			{
				*num2 ^= data[i];
			}
		}

	}
};