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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		if (root->left == NULL && root->right == NULL)
		{
			return ; 
		}
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};