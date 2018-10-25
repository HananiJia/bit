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
 /*class Solution {
 public:
	 TreeNode* trimBST(TreeNode* root, int L, int R) {
		 if (root == NULL)
		 {
			 return NULL;
		 }
		 if (root->val == L)
		 {
			 root->left = NULL;
		 }
		 if (root->val == R)
		 {
			 root->right = NULL;
		 }
		 if (root->val<L)
		 {
			 root = root->right;
		 }
		 if (root->val>R)
		 {
			 root = root->left;
		 }
		 if (root != NULL)
		 {
			 trimBST(root->left, L, R);
			 trimBST(root->right, L, R);
		 }
		 return root;
	 }
 };*/

 //class Solution {
 //public:
	// TreeNode* trimBST(TreeNode* root, int L, int R) {
	//	 if (root == NULL)
	//	 {
	//		 return NULL;
	//	 }
	//	 if (root->val == L)
	//	 {
	//		 root->left = NULL;
	//	 }
	//	 if (root->val == R)
	//	 {
	//		 root->right = NULL;
	//	 }

	//	 trimBST(root->left, L, R);
	//	 trimBST(root->right, L, R);

	//	 return root;
	// }
 //};

 class Solution {
 public:
	 TreeNode* trimBST(TreeNode* root, int L, int R) {
		 if (root == NULL)
			 return NULL;
		 if (root->val < L)
		 {
			 return  trimBST(root->right, L, R);
		 }
		 if (root->val>R)
		 {
			 return trimBST(root->left, L, R);
		 }
		 root->left = trimBST(root->left, L, R);
		 root->right = trimBST(root->right, L, R);
		 return root;
	 }

 };