#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	/*int TreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		return (TreeDepth(root->left)) > (TreeDepth(root->right)) ? (1 + TreeDepth(root->left)) : (1 + TreeDepth(root->right));
	}*/
	int TreeDepth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		queue<TreeNode*> tree;
		tree.push(root);
		int deep = 0;
		while (!tree.empty())
		{
			int n = tree.size();
			for (int i = 0; i < n; i++)
			{
				TreeNode* cur = tree.front();
				tree.pop();
				if (cur->left)
					tree.push(cur->left);
				if (cur->right)
					tree.push(cur->right);
			}
			deep++;
		}
		return deep;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)
			return true;
		int left = TreeDepth(root->left);
		int right = TreeDepth(root->right);
		if (abs(left - right) > 1)
			return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};