#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		int maxpos = vectormax(nums, 0, nums.size()-1);
		TreeNode* root = Construct(nums, 0, nums.size() - 1,maxpos);
		return root;
	}
private:
	TreeNode* Construct(vector<int>&nums, int left, int right,int maxpos)
	{	
		if (maxpos<0 || maxpos>nums.size() - 1)
			return NULL;
		if (right < left)
			return NULL;
		TreeNode* root = new TreeNode(nums[maxpos]);
		int leftmax = vectormax(nums, left, maxpos - 1);
		root->left = Construct(nums, left, maxpos - 1, leftmax);
		int rightmax = vectormax(nums, maxpos+1, right);
		root->right = Construct(nums, maxpos + 1, right, rightmax);
		return root;
	}
	int vectormax(vector<int>& nums, int left, int right)
	{
		int max = nums[left];
		int maxpos = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				maxpos = i;
			}
		}
		return maxpos;
	}
};
int main()
{
	Solution A;
	vector<int> temp;
	temp.push_back(3);
	temp.push_back(2);
	temp.push_back(1);
	temp.push_back(6);
	temp.push_back(0);
	temp.push_back(5);
	A.constructMaximumBinaryTree(temp);
}