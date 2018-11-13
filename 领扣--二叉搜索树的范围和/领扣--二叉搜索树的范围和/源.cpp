#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
	 int rangeSumBST(TreeNode* root, int L, int R) {
		 if (root == NULL || L>R)
		 {
			 return 0;
		 }
		 return RangSum(root, L, R);
	 }
	 int RangSum(TreeNode* root, int l, int r)
	 {
		 int sum = 0;
		 if (root == NULL)
			 return 0;
		 if (root->val <= r&&root->val >= l)
		 {
			 sum += root->val;
			 sum += RangSum(root->right, l, r);
			 sum += RangSum(root->left, l, r);
		 }
		 if (root->val < l)
		 {
			 sum += RangSum(root->right, l, r);
		 }
		 if (root->val>r)
		 {
			 sum += RangSum(root->left, l, r);
		 }
		 return sum;
	 }
 };