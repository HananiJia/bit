#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>



struct TreeLinkNode {
int val;
struct TreeLinkNode *left;
struct TreeLinkNode *right;
struct TreeLinkNode *next;
TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == NULL)
			return	NULL;		
		if (pNode->right != NULL)
		{
				TreeLinkNode *find=pNode->right;
				while (find->left)
				{
					find = find->left;
				}		
				return find;
		}
		{		
			while (pNode->next)
			{
				TreeLinkNode *find = pNode->next;
				if (find->left == pNode)
					return find;
				pNode = pNode->next;				
			}
			return	NULL;
		}
		
	}
};