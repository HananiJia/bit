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

 /*class Solution {
 public:
	 vector<double> averageOfLevels(TreeNode* root) {
		 vector<double> ret;
		 vector<vector<int>> temp;
		 int level = 1;
		 Averageoflevel(temp, root, level);
		 ret.push_back(temp[0][0]);
		 for (int i = 1; i < temp.size(); i++)
		 {
			 double sum = 0;
			 for (int j = 0; j < temp.size(); j++)
			 {
				 sum += temp[i][j];
			 }
			 ret.push_back(sum / temp.size());
		 }
		 return ret;
	 }
	 void Averageoflevel(vector<vector<int>>& temp, TreeNode* root, int level)
	 {
		 if (root == NULL)
			 return;
		 int size = temp.size();
		 if (size < level)
		 {
			 vector<int> a;
			 temp.push_back(a);
		 }
		 temp[level - 1].push_back(root->val);
		 Averageoflevel(temp, root->left, level + 1);
		 Averageoflevel(temp, root->right, level + 1);
		 return;

	 }
 };*/

 class Solution {
 public:
	 vector<double> averageOfLevels(TreeNode* root) {
		 vector<double> ret;
		 queue<TreeNode*> tree;
		 tree.push(root);
		 while (!tree.empty())
		 {
			 int size = tree.size();
			 double sum = 0;
			 for (int i = 0; i < size; i++)
			 {
				 TreeNode* cur = tree.front();
				 tree.pop();
				 sum += cur->val;
				 if (cur->left)
					 tree.push(cur->left);
				 if (cur->right)
					 tree.push(cur->right);
			 }
			 ret.push_back(sum / size);
		 }
		 return ret;
	 }
 };