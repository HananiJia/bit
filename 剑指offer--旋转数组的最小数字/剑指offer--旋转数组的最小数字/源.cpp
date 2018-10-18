#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)
//			return 0;
//		sort(rotateArray.begin(), rotateArray.end());
//		return rotateArray[0];
//
//	}
//};

//class Solution {
//public:
//	int minNumberInRotateArray(vector<int> rotateArray) {
//		if (rotateArray.size() == 0)
//			return 0;
//		for (int i = 0; i < rotateArray.size(); i++)
//		{
//			if (rotateArray[i]>rotateArray[i + 1])
//				return rotateArray[i + 1];
//		}
//		return rotateArray[0];
//	}
//};

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int left = 0;
		int right = rotateArray.size() - 1;
		while (left <= right)
		{
			int middle = (left + right) / 2;
			if (rotateArray[middle] > rotateArray[right])
			{
				left = middle + 1;
			}
			else
			{
				if (rotateArray[middle] == rotateArray[right])
				{
					right--;
				}
				else
				{
					right = middle;
				}
			}
		}
		return rotateArray[left];
	}
};
