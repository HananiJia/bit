#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

 struct TreeNode {
    int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode* left1 = NULL;
		TreeNode* left2 = NULL;
		TreeNode* right1 = NULL;
		TreeNode* right2 = NULL;
		TreeNode* root;
		if (t1 == NULL&&t2 == NULL)
		{
			return NULL;
		}
		else
		{
			if (t1 != NULL&&t2!=NULL)
			{
				root = new TreeNode(t1->val + t2->val);
				left1 = t1->left;
				left2 = t2->left;
				right1 = t1->right;
				right2 = t2->right;
                
			}
			else
			{
				if (t1 != NULL)
				{
					root = new TreeNode(t1->val);
					left1 = t1->left;
					right1 = t1->right;
				}
				else
				{
					root = new TreeNode(t2->val);
					left2 = t2->left;
					right2 = t2->right;
				}
			}
		}
		root->left = mergeTrees(left1, left2);
		root->right = mergeTrees(right1, right2);
		return root;
	
	}
	
};