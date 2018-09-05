#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
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
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return Symmetrical(pRoot,pRoot);
	}
	bool Symmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot1 == NULL&&pRoot2 == NULL)//如果这个没进去说明其中有一个或者两个是空的
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
		{
			return false;//进来的话说明不是两个都是空，但是有一个是空的所以返回错误
		}
		//再往下走说明两个都不是空，所以判断如果两个相等就继续往下判断，如果不相等就返回错误
		if (pRoot1->val != pRoot2->val)
		{
			//两个都不是空但是值不一样说明是错误的
			return false;
		}
		//走到这里说明两个都不为空并且值相等那就要去比较他们的孩子
		return (Symmetrical(pRoot1->left, pRoot2->right) && Symmetrical(pRoot1->right, pRoot2->left));
	}
};