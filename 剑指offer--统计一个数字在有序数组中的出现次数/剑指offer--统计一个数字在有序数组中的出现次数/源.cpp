#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int length = data.size();//求数组长度
		int i = 0;
		int count = 0;
		while (i < length)
		{
			if (data[i] == k)
			{
				count++;
			}
			if (data[i]>k)
				break;
			i++;
		}
		return count;

	}
};

//利用二分法来求
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int length = data.size();//求数组长度
		int mid = length/2;//中间的位置下标
		int left = 0;
		int right = length-1;
		int count = 0;
		while (left<=right)
		{
			mid = (left + right) / 2;
			if (data[mid] == k)
				break;
			if (data[mid] > k)
			{
				right=mid-1;	//如果说mid的数据比k要大说明k在mid 的左边
			}
			else
			{
				left=mid+1;
			}
		}
		//退出循环的时候已经找到k了或者说里边没有k
		if (left > right)
		{
			return 0;
		}
		else
		{
			int mid2 = mid;
			while (data[mid] == k && mid>=0)
			{
				count++;
				mid--;
			}
			while (data[mid2] == k&&mid2<=length)
			{
				count++;
				mid2++;
			}

		}
		return count - 1;
	
	
	}
};

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int left = 0;
		int length = data.size() - 1;
		int right = data.size() - 1;
		int mid = FindK(data, left, right, k);
		int mid2 = mid;
		int count = 0;
		if (mid == -1)
			return 0;
		while ( mid >= 0 && data[mid] == k)
		{
			count++;
			mid--;
		}
		while (mid2 <= length&&data[mid2] == k)
		{
			count++;
			mid2++;
		}
		return count - 1;

	}
private:
	int FindK(vector<int> data, int left, int right, int k)
	{
		int mid = (left + right) / 2;
		if (left > right)
			return -1;
		if (data[mid] == k)
		{
			return mid;
		}
		if (data[mid] > k)
		{
			return FindK(data, left, mid - 1, k);
			
		}
		else
		{
			return FindK(data, mid + 1, right, k);
		}
	}
};
