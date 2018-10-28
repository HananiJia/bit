#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* pruneTree(TreeNode* root) {
		if (root==NULL)
		root=Prune(root);
		return root;
	}

	TreeNode* Prune(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		if (root->left != NULL)
			root->left = Prune(root->left);
		if (root->right != NULL)
			root->right = Prune(root->right);
		if (root->left == NULL&&root->right == NULL&&root->val == 0)
			return NULL;
		return root;
	}
};

int main()
{
	TreeNode* n1=(TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->left = NULL;
	n1->val = 1;
	n1->right = n2;
	n2->val = 0;
	n2->left = n3;
	n2->right = n4;
	n3->val = 0;
	n3->left = NULL;
	n3->right = NULL;
	n4->val = 1;
	n4->left = NULL;
	n4->right = NULL;
	Solution A;
	TreeNode* root;
	root=A.pruneTree(n1);
	system("pause");
	return 0;
}