#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		if (root == NULL)
		{
			return ret;
		}
		string path = "";
		BrinaryTree(ret, path, root);
		return ret;
	}
	void BrinaryTree(vector<string>& ret, string path, TreeNode* root)
	{
		string num = to_string(root->val);
		path = path + num + "->";
		if (root->left == NULL&&root->right == NULL)
		{
			int length = path.size();
			path = path.substr(0, length - 2);
			ret.push_back(path);
			return;
		}
		if (root->left)
			BrinaryTree(ret, path, root->left);
		if (root->right)
			BrinaryTree(ret, path, root->right);
		return;
	}

};