#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
 
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		int count1 = 0;
		int count2 = 0;
		int count = 0;
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1)
		{
			count1++;
			p1 = p1->next;
		}
		while (p2)
		{
			count2++;
			p2 = p2->next;
		}
		if (count1 >= count2)
		{
			count = count1 - count2;
			p1 = pHead1;
			p2 = pHead2;
			while (count)
			{
				p1 = p1->next;
				count--;
			}
		}
		else
		{
			count = count2 - count1;
			p1 = pHead1;
			p2 = pHead2;
			while (count)
			{
				p2 = p2->next;
				count--;
			}
		}
		while (p1 != NULL&&p2 != NULL)
		{
			if (p1 == p2)
				return p1;
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}

		return NULL;
	}
};