#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;

	DataType _data;
}BSTreeNode;

/////////////////////////////////////////////////////// 
// 非递归 
BSTreeNode* BuyBSTreeNode(DataType x)
{
	BSTreeNode *NewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	NewNode->_data = x;
	NewNode->_left = NULL;
	NewNode->_right = NULL;

	return NewNode;
}
int BSTreeInsert(BSTreeNode** tree, DataType x)
{
	BSTreeNode *cur = *tree;
	BSTreeNode *parent = *tree;
	BSTreeNode *New = NULL;
	if (*tree == NULL)
	{
		*tree=BuyBSTreeNode(x);
		return 0;
	}
	while (cur)
	{

		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			if (cur->_data < x)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return -1;
			}
		}
	}
	New = BuyBSTreeNode(x);
	if (parent->_data>x)
	{
		parent->_left = New;

	}
	else
	{
		parent->_right = New;
	}
	return 0;

}
const BSTreeNode* BSTreeFind(BSTreeNode* tree, DataType x)
{
	BSTreeNode *cur = tree;
	while (cur)
	{
		if (cur->_data > x)
		{
			cur = cur->_left;
		}
		else
		{
			if (cur->_data < x)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;
			}
		}
	}
	return NULL;
}
int BSTreeRemove(BSTreeNode** tree, DataType x)
{
	BSTreeNode *cur = *tree;
	BSTreeNode *parent = *tree;
	BSTreeNode *next = NULL;
	assert(*tree);
	if ((cur->_left == NULL) && (cur->_right = NULL))
	{

		*tree = NULL;
		return 0;
	}
	while (cur)
	{
	
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else
		{
			if (cur->_data < x)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				break;
			}
		}
	}
	if (cur == NULL)
	{
		printf("没有找到数据\n");
		return -1;
	}
	//左右都不为空的情况说明需要找数值来替换他 找左孩子的最右孩子或者右孩子的最左孩子
	if ((cur->_left != NULL) && (cur->_right != NULL))
	{
		if (cur->_right->_left != NULL)
		{
			parent = cur->_right;
			next = cur->_right->_left;
			while (next->_left)
			{
				parent = next;
				next = next->_left;
			}
			cur->_data = next->_data;
			cur = next;
		}
		else
		{
			next = cur->_right;
			if (parent->_left == cur)
			{
				parent->_left = cur->_right;
			}
			else
			{
				parent->_right = cur->_right;
			}
			next->_left = cur->_left;
			free(cur);
			cur = NULL;
			return 0;
		}
		
	}
	if (cur->_left == NULL)//左为空，或者右为空的处理方式都是一样的叶子也可以看成特殊的左为空
	{
		if (parent->_left == cur)
		{
			parent->_left = cur->_right;
		}
		else
		{
			parent->_right = cur->_right;
		}
		free(cur);
		cur = NULL;
		return 0;
	}
	if (cur->_right == NULL)
	{
		if (parent->_left == cur)
		{
			parent->_left = cur->_left;
		}
		else
		{
			parent->_right = cur->_left;
		}
		free(cur);
		cur = NULL;
		return 0;
	}
	


}
void BSTreeDestory(BSTreeNode* tree);

/////////////////////////////////////////////////////// 
// 递归 
int BSTreeInsertR(BSTreeNode** tree, DataType x)
{
	if (*tree == NULL)
	{
		*tree = BuyBSTreeNode(x);
		return 0;
	}
	if ((*tree)->_data > x)
	{
		return BSTreeInsertR(&(*tree)->_left, x);
	}
	else if ((*tree)->_data < x)
	{
		return BSTreeInsertR(&(*tree)->_right, x);
	}
	else return -1;
}
const BSTreeNode* BSTreeFindR(BSTreeNode* tree, DataType x)
{
	if (tree == NULL)
	{
		return NULL;
	}
	if (tree->_data > x)
	{
		return BSTreeFindR(tree->_left, x);
	}
	else if (tree->_data < x)
	{
		return BSTreeFindR(tree->_right, x);
	}
	else
	{
		return tree;
	}
}
int BSTreeRemoveR(BSTreeNode** pptree, DataType x)
{

	BSTreeNode*cur = *pptree;
	BSTreeNode*del = cur;
	BSTreeNode*sub = NULL;
	if (NULL == *pptree)//空
	{
		return -1;
	}
	assert(pptree);
	if (cur->_data>x)
	{
		return BSTreeRemoveR(&(cur->_left), x);
	}
	else if (cur->_data<x)
	{
		return BSTreeRemoveR(&(cur->_right), x);
	}
	else//找到后进行删除
	{
		del = cur;//记录要删除的点
		if (cur->_left == NULL)//左为空
		{
			*pptree = cur->_right;
		}
		else if (cur->_right == NULL)//右为空
		{
			*pptree = cur->_left;
		}
		else//左右都不为空
		{
			sub = cur->_right;
			while (sub->_left)
			{
				sub = sub->_left;
			}
			del = sub;
			cur->_data = sub->_data;
			return BSTreeRemoveR(&(cur->_right), sub->_data);
		}
		free(del);
		del = NULL;
		return 0;
	}
}

//void TestBSTree() 
//{ 
//	//BSTreeNode* tree = NULL; 
//	//BSTreeInsert(&tree, 4); 
//	//BSTreeInsert(&tree, 2); 
//	//BSTreeInsert(&tree, 1); 
//	//BSTreeInsert(&tree, 3); 
//	//BSTreeInsert(&tree, 2); 
// 
//	//const BSTreeNode* node = BSTreeFind(tree, 2); 
//	//printf("Find 2? %d\n", node->_data); 
// 
//	int a[] = {5,3,4,1,7,8,2,6,0,9}; 
//	BSTreeNode* tree = NULL; 
// 
//	for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) 
//	{ 
//	BSTreeInsert(&tree, a[i]); 
//	} 
//	
//	BSTreeInOrder(tree); 
//	printf("\n"); 
// 
//	BSTreeRemove(&tree, 4); 
//	BSTreeRemove(&tree, 8); 
//	BSTreeRemove(&tree, 3); 
//	BSTreeRemove(&tree, 7); 
//	BSTreeRemove(&tree, 5); 
// 
//	BSTreeInOrder(tree); 
//	printf("\n"); 
// 
//	BSTreeRemove(&tree, 0); 
//	BSTreeRemove(&tree, 1); 
//	BSTreeRemove(&tree, 2); 
//	BSTreeRemove(&tree, 3); 
//	BSTreeRemove(&tree, 4); 
//	BSTreeRemove(&tree, 5); 
//	BSTreeRemove(&tree, 6); 
//	BSTreeRemove(&tree, 7); 
//	BSTreeRemove(&tree, 8); 
//	BSTreeRemove(&tree, 9); 
// 
//	BSTreeInOrder(tree); 
//	printf("\n"); 
//}; 
void BTreeInOrder(BSTreeNode* root)//中序遍历  

{

	if (root == NULL)

		return;

	else

	{

		BTreeInOrder(root->_left);

		printf("%d", root->_data);

		BTreeInOrder(root->_right);



	}

}
int main()
{
	/*BSTreeNode* tree = NULL;*/ 
	//BSTreeInsert(&tree, 4); 
	//BSTreeInsert(&tree, 2); 
	//BSTreeInsert(&tree, 1); 
	//BSTreeInsert(&tree, 3); 
	//BSTreeInsert(&tree, 2); 
	//printf("%d", tree->_left->_data);
		int a[] = {5,3,4,1,7,8,2,6,0,9}; 
		BSTreeNode* tree = NULL; 
	 
		for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) 
		{ 
		BSTreeInsertR(&tree, a[i]); 
		} 
		BTreeInOrder(tree);
		printf("\n");
		const BSTreeNode* node = BSTreeFind(tree, 2); 
		printf("Find 2? %d\n", node->_data); 
		const BSTreeNode* node1 = BSTreeFindR(tree, 9);
		printf("Find 2? %d\n", node1->_data);
			BSTreeRemoveR(&tree, 5); 
		//	BSTreeRemove(&tree, 8); 
		//	BSTreeRemove(&tree, 3); 
		//	BSTreeRemove(&tree, 7); 
		//	BSTreeRemove(&tree, 5); 
			BTreeInOrder(tree);
	system("pause");
	return 0;
}