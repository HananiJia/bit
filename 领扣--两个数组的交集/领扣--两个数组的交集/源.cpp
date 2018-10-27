#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		set<int> tem;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums2[j] == nums1[i])
				{
					tem.insert(nums1[i]);
					break;
				}
			}
		}
		for (auto k:tem)
		{
			ret.push_back(k);
		}
		return ret;
	}
};