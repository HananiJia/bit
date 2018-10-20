#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> ret;
//		vector<int> t;
//		ret.push_back(t);//先插入一个空集
//		for (int length = 1; length <= nums.size(); length++)//子集数组的长度，从1开始到和数组长度相同
//		{
//			for (int start = 0; start < nums.size(); start++)//插入数据的起始位置
//			{
//				vector<int> temp;
//				if (start + length>nums.size() - 1)//防止访问越界
//					break;
//				for (int go = start; go < start + length; go++)//从go开始走，到了子集数组长度时就停
//				{
//					if (go>nums.size() - 1)
//						break;
//					temp.push_back(nums[go]);
//				}
//				ret.push_back(temp);
//		
//			}
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret(1);
		if (nums.size() == 0)
			return ret;
		for (int i = 0; i<nums.size(); i++)
		{
			int size = ret.size();
			for (int j = 0; j<size; j++)
			{
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}
};