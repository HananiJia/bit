#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *NewNode=new ListNode(-1);
		NewNode->next = NULL;
		NewNode->val = 0;
		if (l1->val < l2->val)
		{
			NewNode->val = l1->val;
			l1 = l1->next;
		}
		else
		{
			NewNode->val = l2->val;
			l2 = l2->next;
		}
		ListNode *cur = NewNode;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
				cur = cur->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
				cur = cur->next;
			}
		}
		if (l1)
		{
			cur->next = l1;
		}
		else
		{
			cur->next = l2;
		}
		return NewNode;
	}
};