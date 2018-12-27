#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int maxSubArray(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		int maxsub = nums[0];
//		for (int i = 0; i < nums.size(); i++)
//		{
//			int max = maxArray(nums, i);
//			if (max>maxsub)
//				maxsub = max;
//		}
//		return maxsub;
//	}
//	int maxArray(vector<int>& nums, int begin)
//	{
//		int max = nums[begin];
//		int retmax = nums[begin];
//		for (int i = begin+1; i < nums.size(); i++)
//		{
//			max += nums[i];
//			if (max>retmax)
//				retmax = max;
//		}
//		return retmax;
//	}
//};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int ret = sum;
		for (int i = 1; i < nums.size(); i++)
		{
			if (sum < 0)
				sum = nums[i];
			else
				sum += nums[i];
			if (sum>ret)
				ret = sum;
		}
		return ret;
	}
};

int main()
{
	Solution A;
	vector<int> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	cout<<A.maxSubArray(a);
	system("pause");
	return 0;
}