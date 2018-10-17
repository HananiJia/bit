#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;     
	TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		int middle = nums.size() / 2;
		TreeNode* root = new TreeNode(nums[middle]);
		vector<int> left = vector<int>(nums.begin(), nums.begin()+middle);
		vector<int> right = vector<int>(nums.begin() + middle + 1, nums.end());
		root->left = sortedArrayToBST(left);
		root->right = sortedArrayToBST(right);
		return root;

	}
};