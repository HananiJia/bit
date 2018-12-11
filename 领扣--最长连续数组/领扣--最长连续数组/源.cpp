#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//class Solution {
//public:
//	int longestConsecutive(vector<int>& nums) {
//		if (nums.empty())
//			return 0;
//		if (nums.size() == 1)
//			return 1;
//		sort(nums.begin(), nums.end());
//		int index = 1;
//		int maxlen = 1;
//		int size = nums.size();
//		while (index < size)
//		{
//			int len = 1;
//			while (index<size&&nums[index] != nums[index - 1] + 1)
//			{
//				index++;
//			}
//			if (index >= size)
//				break;
//			while (index<size && (nums[index] == nums[index - 1] + 1 || nums[index] == nums[index - 1]))
//			{
//				index++;
//				len++;
//			}
//			maxlen = max(maxlen, len);
//			
//		}
//		return maxlen;
//	}
//};


class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return 1;
		int maxlen = 0;
		map<int, int> m;
		for (auto i : nums)
		{
			int left = 0;
			int right = 0;
			if (m.find(i - 1)!=m.end())
			{
				left = m[i - 1];
			}
			if (m.find(i + 1) != m.end())
			{
				right = m[i + 1];
			}
			int len = left + right + 1;
			m.insert(i, len);
			maxlen = max(maxlen, len);
			m.insert(i - left, len);
			m.insert(i - right, len);
		}
		return maxlen;
	}
};
int main()
{
	Solution A;
	vector<int> a = { 100, 4, 200, 6, 3, 5,2 };
	cout<<A.longestConsecutive(a);
	system("pause");
	return 0;
}

