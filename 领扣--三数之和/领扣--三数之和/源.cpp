#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
/*class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			set<vector<int>> ret;
			for (int i = 0; i < nums.size(); i++)
			{
				TwoNumSum(ret, nums, i, 0 - nums[i]);
			}
			vector<vector<int>> r;
			for (auto k : ret)
			{
				r.push_back(k);
			}
			return r;
		}
		void TwoNumSum(set<vector<int>>& ret, vector<int>& nums, int pos, int sum)
		{
			for (int i = pos + 1; i < nums.size() - 1; i++)
			{
				for (int j = i + 1; j < nums.size(); j++)
				{
					if (nums[i] + nums[j] == sum)
					{
						vector<int> temp(1, nums[pos]);
						temp.push_back(nums[i]);
						temp.push_back(nums[j]);
						sort(temp.begin(), temp.end());
						ret.insert(temp);
						break;
					}
				}
			}
			return;
		}
	};*/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector < vector<int>> ret;
		sort(nums.begin(), nums.end());//对他进行排序
		if (nums.size() == 0 || nums.front() > 0 || nums.back() < 0)
			return ret;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i]>0)
				break;
			if (i>0 && nums[i] == nums[i - 1])
				continue;
			int target = 0 - nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				int num = nums[left] + nums[right];
				if (num == target)
				{
					vector<int> temp = { nums[i], nums[left], nums[right] };
					ret.push_back(temp);
					while (left<right&&nums[left] == nums[left + 1])left++;
					while (left<right&&nums[right] == nums[right - 1])right--;
					right++;
					left++;
				}
				if (num>target)
				{
					right--;
				}
				if (num < target)
				{
					left++;
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution A;
	vector<int> a = { -2, 0, 1, 1, 2 };
	vector<vector<int>> b;
	b=A.threeSum(a);
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			cout << b[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

