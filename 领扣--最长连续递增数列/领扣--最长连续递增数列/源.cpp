#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int findLengthOfLCIS(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		int maxlen = 0;
//		if (nums.size() == 1)
//			return maxlen;
//		for (int i = 1; i < nums.size(); i++)
//		{
//			if (nums[i]>nums[i - 1])
//			{
//				int len = MaxLengthAdd(nums, i);
//				if (len > maxlen)
//					maxlen = len;
//			}
//		}
//		return maxlen;
//	}
//	int MaxLengthAdd(vector<int>& nums, int pos)
//	{
//		int maxlen = 1;
//		for (int i = pos; i < nums.size(); i++)
//		{
//			if (nums[i]>nums[i - 1])
//			{
//				maxlen++;
//			}
//			else
//			{
//				break;
//			}
//		}
//		return maxlen;
//	}
//};
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size();
		int maxlen = 0;
		int start = 0;
		int end = 1;
		while (end < n)
		{
			if (nums[end] <= nums[end - 1])
			{
				maxlen = max(maxlen, end - start);
				start = end;
			}
			end++;
		}
		maxlen = max(maxlen, end - start);
		return maxlen;
	}
};
int main()
{
	Solution A;
	vector<int> a = { 1, 3, 5, 4, 7 };
	cout << A.findLengthOfLCIS(a) << endl;
	system("pause");
	return 0;
}