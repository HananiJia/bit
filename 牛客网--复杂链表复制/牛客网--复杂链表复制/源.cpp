#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


RandomListNode* Clone(RandomListNode* pHead)
{
	RandomListNode *NewpHead = NULL;
	RandomListNode *Move = pHead;
	RandomListNode *Copy = NULL;
	if (pHead == NULL)
		return NULL;
	while (Move)
	{
		RandomList *cur = new RandomListNode(Move->label);
		cur->next = Move->next;
		Move->next = cur;
		Move = cur->next;
	}
	Move = pHead;
	Copy = Move->next;
	while (Copy)
	{
		if (Move->random == NULL)
		{
			Copy->random = NULL;
		}
		else
		{
			Copy->random = Move->random->next;			
		}
		Move = Copy->next;
		Copy = Move->next;
	}
	Move = pHead;
	NewpHead = pHead->next;
	RandomListNode *tmp = NULL;
	while (Move->next)
	{
		tmp = Move->next;
		Move->next = Move->next;
		cur = tmp;
		/*Move->next = Copy->next;
		Move = Move->next;
		Copy->next = Move->next;
		Copy = Copy->next;*/
		/*Copy = Move->next;
		Move->next = Copy->next;
		Copy->next = Move->next->next;*/
	}
	return NewpHead;

}

RandomListNode* Clone(RandomListNode* pHead)
{
	RandomListNode *cur = pHead;
	RandomListNode *copy = NULL;
	RandomListNode *clone = NULL;
	while (cur)
	{
		copy = new RandomListNode(cur->label);
		copy->next = cur->next;
		cur->next = copy;
		cur = copy->next;

	}
	cur = pHead;
	copy = cur->next;
	while (cur)
	{
		if (cur->random != NULL)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = copy->next;
		copy = cur->next;
	}
	cur = pHead;
	clone = cur->next;

	while (cur->next)
	{
		copy = cur->next;
		cur->next = copy->next;
		copy->next = cur->next->next;
	}
	return clone;


}


int main()
{

}