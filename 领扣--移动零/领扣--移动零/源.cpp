#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std; 

//class Solution {
//public:
//	void moveZeroes(vector<int>& nums) {
//		if (nums.size() <= 1)
//			return;
//		int zero = 0;
//		int notzero = 0;
//		for (int i = 0; i < nums.size(); i++)
//		{
//			zero = FindZero(nums, i);
//			notzero = FindNotZero(nums, i);
//			if (zero == nums.size()||notzero==nums.size())
//				break;
//			if (zero < notzero)
//			{
//				nums[zero] = nums[notzero];
//				nums[notzero] = 0;
//			}
//		}
//	}
//	int FindZero(vector<int>& nums, int start)
//	{
//		for (int i = start; i < nums.size(); i++)
//		{
//			if (nums[i] == 0)
//				return i;
//		}
//		return nums.size();
//	}
//	int FindNotZero(vector<int>& nums, int start)
//	{
//		for (int i = start; i < nums.size(); i++)
//		{
//			if (nums[i] != 0)
//				return i;
//		}
//		return nums.size();
//	}
//};

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() <= 1)
			return;
		int fast = 0;
		int slow = 0;
		while (fast < nums.size())
		{
			//如果找到0了就让fast去找非0的然后找到之后交换
			//如果没找到两个就一起一直往后找
			if (nums[fast] != 0)
			{
				if (fast != slow)
				{
					nums[slow] = nums[fast];
					nums[fast] = 0;
				}
				slow++;
				fast++;
			}
			else
			{
				fast++;
			}
		}
	}
};

int main()
{
	Solution A;
	vector<int> a = { 0,1,0,3,12};
	A.moveZeroes(a);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
	return 0;
}