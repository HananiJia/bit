#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		queue<TreeNode*> tree;
		tree.push(root);
		while (!tree.empty())
		{
			TreeNode* now = tree.front();
			ret.push_back(tree.front()->val);
			tree.pop();
			if (now->left)
			{
				tree.push(now->left);
			}
			if (now->right)
			{
				tree.push(now->right);
			}
			
		}
		return ret;		
	}
};