#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int search(vector<int>& nums, int target) {
//		for (int i = 0; i < nums.size(); i++)
//		{
//			if (nums[i] == target)
//				return i;
//		}
//		return -1;
//	}
//};


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return -1;
		int start = 0;
		int end = nums.size() - 1;
		int mid = (start + end) / 2;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (nums[mid] == target)
				return mid;
			//下边是没找到的情况
			//因为这个数组是递增的所以中间的左边或者右边一定是有一边是有序的，另一边不一定
			if (nums[mid] >= nums[start])
			{
				//左边有序
				if (nums[start] <= target&&nums[mid] > target)
				{
					//在左边区间
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			else
			{
				//右边有序
				if (target<=nums[end]&&nums[mid] < target)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
		}
		return -1; 
	}
};

int main()
{
	Solution A;
	vector<int> a = { 3,1 };
	cout<<A.search(a,1);
	system("pause");
	return 0;
}