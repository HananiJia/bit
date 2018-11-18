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

//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> ret;
//		LevelOrder(ret, 1, root);
//		return ret;
//	}
//	void LevelOrder(vector<vector<int>>& a, int level, TreeNode* root)
//	{
//		if (root == NULL)
//			return;
//		if (a.size() < level)
//		{
//			vector<int> temp;
//			a.push_back(temp);
//		}
//		a[level - 1].push_back(root->val);
//		LevelOrder(a, level + 1, root->left);
//		LevelOrder(a, level + 1, root->right);
//		return;
//	}
//};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		queue<TreeNode*> tree;
		tree.push(root);
		tree.push(NULL);
		vector<int> temp;
		while (!tree.empty())
		{
			TreeNode* cur = tree.front();
			tree.pop();
			if (cur == NULL)//说明这是一个两层之间的分界线
			{//让自己的一维数组清空
				if (!tree.empty())
				{
					tree.push(NULL);//如果你现在读到空了说明，当前这一层读完了也不会再添加他们的孩子了
					ret.push_back(temp);
					temp.resize(0);
				}
			}
			else
			{
				temp.push_back(cur->val);
				if (cur->left)
				tree.push(cur->left);
				if (cur->right)
				tree.push(cur->right);
			}
		}
		return ret;
	}
};