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
		printf("%3d", cur->_data);
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

SListNode* SListMerge(SListNode* list1, SListNode* list2)
{
	SListNode *New=BuySListNode(0);
	SListNode*head=New;
	while (list1&&list2 )
	{
		if ((list1->_data) < (list2->_data))
		{
			SListPushBack(&New,list1->_data );
			list1 = list1->_next;
		}
		else
		{
			SListPushBack(&New, list2->_data);
			list2 = list2->_next;
		}
		
		
	}
	if (list1 == NULL)
	{
		while (list2)
		{
			SListPushBack(&New, list2->_data);
			list2 = list2->_next;
		}
	}
	if (list2 == NULL)
	{

		while (list1)
		{
			SListPushBack(&New, list1->_data);
			list1 = list1->_next;
		}
	}

	return head;
}

int main()
{
	SListNode* SList;
	SListNode* SList1;
	SListNode* SList2;
	SList = BuySListNode(1);

	SListPushBack(&SList, 2);
	SListPushBack(&SList, 3);
	SListPushBack(&SList, 4);
	SListPushBack(&SList, 8);
	SListPushBack(&SList, 9);
	SListPushBack(&SList, 13);
	printf("第一个链表为:\n");
	SListPrint(SList);
	SList1 = BuySListNode(5);
	SListPushBack(&SList1, 6);
	SListPushBack(&SList1, 7);
	SListPushBack(&SList1, 10);
	SListPushBack(&SList1, 11);
	SListPushBack(&SList1, 12);
	SListPushBack(&SList1, 14);
	printf("\n");
	printf("第二个链表为:\n");
	SListPrint(SList1);
	printf("\n");
	printf("合并后的链表为\n");
	SList2 = SListMerge(SList, SList1);
	SListPrint(SList2);
	system("pause");
	
	return 0;
}