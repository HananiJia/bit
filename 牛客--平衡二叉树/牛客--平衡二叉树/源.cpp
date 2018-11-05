#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		int left = deep(pRoot->left);
		int right = deep(pRoot->right);
		int dis = left - right;
		if (dis>1 || dis<-1)
			return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

	}
	int deep(TreeNode* pRoot)
	{
		int left = 0;
		int right = 0;
		if (pRoot == NULL)
			return 0;
		else
		{
			left = deep(pRoot->left);
			right = deep(pRoot->right);
			return left>right ? left + 1 : right + 1;
		}
	}
};
