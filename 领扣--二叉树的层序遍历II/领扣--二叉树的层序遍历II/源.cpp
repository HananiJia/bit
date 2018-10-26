#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //class Solution {
 //public:
	// vector<vector<int>> levelOrderBottom(TreeNode* root) {
	//	 vector <vector < int >> ret;
	//	 queue<TreeNode*> tree;
	//	 if (root == NULL)
	//		 return ret;
	//	 tree.push(root);
	//	 vector<int> temp;
	//	 temp.push_back(root->val);
	//	 ret.push_back(temp);
	//	 while (!tree.empty())
	//	 {
	//		 vector<int> t;
	//		 TreeNode* now = tree.front();
	//		 tree.pop();
	//		 if (now->left != NULL)
	//		 {
	//			 t.push_back(now->left->val);
	//			 tree.push(now->left);
	//		 }
	//		 if (now->right != NULL)
	//		 {
	//			 t.push_back(now->right->val);
	//			 tree.push(now->right);
	//		 }
	//		 if (!t.empty())
	//		 {
	//			 ret.push_back(t);
	//		 }
	//	 }
	//	 vector<vector<int>>  rett;
	//	 for (int i = ret.size(); i >= 0; i--)
	//	 {
	//		 rett.push_back(ret[i]);
	//	 }
	//	 return rett;
	// }
 //};

 //class Solution {
 //public:
	// vector<vector<int>> levelOrderBottom(TreeNode* root) {
	//	 vector<vector<int>> ret;
	//	 if (root == NULL)
	//		 return ret;
	//	 queue<TreeNode*> tree;
	//	 tree.push(root);
	//	 vector<int> temp;
	//	 while (!tree.empty())
	//	 {
	//		 TreeNode* now = tree.front();
	//		 tree.pop();
	//		 if (now->left != NULL)
	//		 {
	//			 tree.push(now->left);
	//		 }
	//		 if (now->right != NULL)
	//		 {
	//			 tree.push(now->right);
	//		 }

	//		 temp.push_back(now->val);
	//	 }
	//	 ret.push_back(temp);
	//	 return ret;
	// }
 //};

 class Solution {
 public:
	 vector<vector<int>> levelOrderBottom(TreeNode* root) {
		 vector<vector<int>> ret;
		 if (root == NULL)
			 return ret;
		 LevelOrder(ret,root,1);
		 vector<vector<int>> rett;
		 for (int i = ret.size() - 1; i >= 0; i--)
		 {
			 rett.push_back(ret[i]);
		 }
		 return rett;

	 }
	 void LevelOrder(vector<vector<int>>& num, TreeNode* root, int level)
	 {
		 if (root == NULL)
			 return ;
		 int size = num.size();
		 if (level > size)
		 {
			 vector<int> temp;
			 temp.push_back(root->val);
			 num.push_back(temp);
		 }
		 else
		 {
			 num[level-1].push_back(root->val);
		 }
		 LevelOrder(num, root->left, level + 1);
		 LevelOrder(num, root->right, level + 1);
		 return;

	 }
 };