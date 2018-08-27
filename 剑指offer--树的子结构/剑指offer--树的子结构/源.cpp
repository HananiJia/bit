#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//		if (pRoot1 == NULL && pRoot2 != NULL)
//			return false;
//		if (pRoot1 != NULL && pRoot2 == NULL)
//			return false;
//		if (pRoot1 == NULL && pRoot2 == NULL)
//			return true;
//		else
//			return (HasSubtree(pRoot1->left, pRoot2->left) && (HasSubtree(pRoot1->right, pRoot2->right)));
//		
//	}
//};



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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL&&pRoot2 != NULL)
		{
			//这时候就要去找大树里边有没有你的子树的根
			if (pRoot1->val == pRoot2->val)
			{
				result = FindHasSubtree(pRoot1, pRoot2);
				//这时候就要开始对比这两个树是不是一样了，根一样了往下对比
			}
				//这时候现在这个结点不一样那就得去他的左孩子或者右孩子里边找找，这里我们用递归比较好
				//这样不需要保存当前结点位置，如果左孩子没有的话会退到当前函数去找右孩子
			if (!result)
			{
				result = HasSubtree(pRoot1->left, pRoot2);//这个结点不是就去他的左孩子里边找
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->right, pRoot2);//左孩子没找到就去右孩子里边找
			}
		}
		return result;
	}
	bool FindHasSubtree(TreeNode *p1, TreeNode *p2)
	{
		//这个函数用来对比两个子树是不是一样，还是用递归
		if (p2 == NULL)//如果2到头了这时候说明匹配完了还没有返回错误的值那就是正确的
			return true;
		if (p1 == NULL)//如果2还没有到底1到底了，那说明不匹配
			return false;
		if (p1->val != p2->val)//遇到两个值不一样说明不匹配
			return false;
		//走到这里说明我们1不是空2也不是空并且两个数值一样，那就去比较他们两个的孩子一样不一样一层一层递归
		return (FindHasSubtree(p1->left, p2->left) && FindHasSubtree(p1->right, p2->right));
	}
};


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	if (pRoot1->val == pRoot2->val)
		return true;
	//这里说明两个节点不相同就需要去孩子里边找
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}