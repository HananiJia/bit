#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	int maxArea(vector<int>& height) {
//		int maxresult = 0;
//		for (int i = 0; i < height.size(); i++)
//		{
//			for (int j = i + 1; j < height.size(); j++)
//			{
//				if (height[i]>height[j])
//				{
//					maxresult = max(maxresult, (j - i)*height[j]);
//				}
//				else
//				{
//					maxresult = max(maxresult, (j - i)*height[i]);
//				}
//				
//			}
//		}
//		return maxresult;
//	}
//};

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size()-1;
		int maxresult=0;
		while (left < right)
		{
			maxresult = max(maxresult, (right - left)*min(height[left], height[right]));
			height[left]>height[right] ? right-- : left++;
			
		}
		return maxresult;
	}
};

int main()
{
	Solution A;
	vector<int> a = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout<<A.maxArea(a)<<endl;
	system("pause");
	return 0;
}