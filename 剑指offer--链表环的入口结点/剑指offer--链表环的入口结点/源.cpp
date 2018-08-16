#define _CRT_SECURE_NO_WARNINGS 1
//��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null
#include<iostream>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode *fast = pHead;
		ListNode *slow = pHead;
		ListNode *meet = NULL;
		int flag = 0;
		while (fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
			{
				flag = 1;
				meet = fast;
				break;
			}
		}
		if (flag == 1)//˵���л�
		{
			slow = pHead;
			while (slow != meet)
			{
				slow = slow->next;
				meet = meet->next;
			}
			return meet;
		}
		else
		{
			return NULL;
		}
	}
};