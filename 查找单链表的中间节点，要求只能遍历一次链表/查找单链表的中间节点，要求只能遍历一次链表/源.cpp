#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


SListNode* BuySListNode(DataType x)
{
	SListNode *NewNode;
	NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
	{
		printf("空间分配失败\n");
	}
	else
	{

		NewNode->_data = x;
		NewNode->_next = NULL;
	}
	return NewNode;

}
void SListPrint(SListNode* pHead)
{
	assert(pHead);
	SListNode*cur = pHead;
	while (cur)
	{
		printf("%d", cur->_data);
		cur = cur->_next;
	}
}
void SListDestory(SListNode** ppHead)
{
	assert(*ppHead);
	SListNode *cur;
	cur = *ppHead;
	while (*ppHead)
	{
		cur = *ppHead;

		*ppHead = (*ppHead)->_next;
		free(cur);

	}

}

void SListPushBack(SListNode** ppHead, DataType x)
{

	SListNode *cur = NULL;
	SListNode *NewNode;
	cur = *ppHead;
	NewNode = BuySListNode(x);
	if (*ppHead == NULL)
	{
		*ppHead = NewNode;
		(*ppHead)->_next = NULL;

	}
	else
	{
		while (cur->_next)
		{
			cur = cur->_next;
		}
		cur->_next = NewNode;
		NewNode->_next = NULL;
	}
	/*SListNode* newNode;
	SListNode* tmp;
	newNode = BuySListNode(x);
	tmp = *ppHead;
	if (NULL == *ppHead)
	{
	*ppHead = newNode;
	(*ppHead)->_next = NULL;
	}
	else
	{
	while (tmp->_next)
	{
	tmp = tmp->_next;
	}
	tmp->_next = newNode;
	newNode->_next = NULL;
	}*/
}
void SListPopBack(SListNode** ppHead)
{
	assert(*ppHead);
	SListNode *cur;
	SListNode *cur2;
	cur = *ppHead;
	if (cur->_next == NULL)
	{
		free(*ppHead);
	}
	else
	{

		while (cur->_next->_next)
		{
			cur = cur->_next;
		}
		cur2 = cur->_next;
		free(cur2);
		cur->_next = NULL;
	}

}
void SListPushFront(SListNode** ppHead, DataType x)
{

	SListNode *cur;
	SListNode *NewNode;
	NewNode = BuySListNode(x);
	if (*ppHead == NULL)
	{
		*ppHead = NewNode;
		(*ppHead)->_next = NULL;
	}
	else
	{
		cur = (*ppHead)->_next;
		(*ppHead)->_next = NewNode;
		NewNode->_next = cur;
	}
}
void SListPopFront(SListNode** ppHead)
{
	assert(*ppHead);
	SListNode *cur;
	if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
	}
	else
	{
		cur = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = cur;

	}
}
SListNode* SListFind(SListNode* pHead, DataType x)
{
	assert(pHead);
	SListNode *pos;
	pos = pHead;
	while (pos)
	{
		if (pos->_data == x)
		{
			return pos;
		}
		pos = pos->_next;
	}
	return NULL;
}
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x)
{
	assert(*ppHead);
	SListNode *cur;
	SListNode *NewNode;

	if (pos == *ppHead)
	{
		SListPushFront(ppHead, x);
		return;
	}
	else
	{
		NewNode = BuySListNode(x);
		cur = *ppHead;
		while ((cur != pos) && (cur != NULL))
		{
			cur = cur->_next;
		}
		if (cur == NULL)
		{
			printf("没有找到对应位置\n");
			return;
		}
		pos = cur->_next;
		cur->_next = NewNode;
		NewNode->_next = pos;

	}
	return;
}
void SListErase(SListNode** ppHead, SListNode* pos)
{
	assert(*ppHead);
	SListNode *cur = *ppHead;
	SListNode *cur2;
	if (pos == *ppHead)
	{
		SListPopFront(ppHead);
		return;
	}
	else
	{
		while ((cur->_next != pos) && (cur != NULL))
		{
			cur = cur->_next;
		}
		cur2 = cur->_next;
		cur->_next = cur2->_next;
		free(cur2);
		cur2 = NULL;
	}
}
SListNode* SListFindMidNode(SListNode* list)
{
	assert(list);
	SListNode *fast=list;
	SListNode *slow=list;
	while (fast)
	{
		if (fast->_next != NULL)
		{

			fast = fast->_next->_next;
			slow = slow->_next;
		}
		else
		{
			break;
		}

	}
	return slow;

}

int main()
{
	SListNode* SList;
	SListNode*mid;
	SList = BuySListNode(1);
	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);
	SListPushBack(&SList, 10);
	SListPushBack(&SList, 9);
	SListPushBack(&SList, 8);
	SListPrint(SList);
	printf("\n");
	mid=SListFindMidNode(SList);
	printf("%d\n",mid->_data);
	system("pause");
	
	return 0;
}