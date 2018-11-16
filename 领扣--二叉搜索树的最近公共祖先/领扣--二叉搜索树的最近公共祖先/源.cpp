#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pp;
		vector<TreeNode*> qq;
		FindNumRoute(pp, root, p);
		FindNumRoute(qq, root, q);
		for (int i = 0; i < pp.size(); i++)
		{
			vector<TreeNode*>::iterator it = find(qq.begin(), qq.end(), pp[i]);
			if (it != qq.end())
				return *it;
		}
		return qq[qq.size()-1];

	}
	void FindNumRoute(vector<TreeNode*>& a, TreeNode* root, TreeNode* cur)
	{
		if (root == NULL)
			return;
		if (root->val == cur->val)
		{
			a.push_back(root);
			return;
		}
		else
		{
			if (root->val > cur->val)//root的值比要找的大往左走
			{
				a.push_back(root);
				FindNumRoute(a, root->left, cur);
			}
			else
			{
				a.push_back(root);
				FindNumRoute(a, root->right, cur);
			}
		}
		return;
	}
};

int main()
{

}