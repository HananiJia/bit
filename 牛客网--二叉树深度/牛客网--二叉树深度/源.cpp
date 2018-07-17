#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	if (TreeDepth(pRoot->left) > TreeDepth(pRoot->right))
	 return 1 + TreeDepth(pRoot->left);
	else
		return 1 + TreeDepth(pRoot->right);

}
int main()
{

}