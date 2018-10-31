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
	ListNode* middleNode(ListNode* head) {
		if (head == NULL)
			return NULL;
		if (head->val == NULL)
			return head;
		ListNode* fast = head->next;
		ListNode* slow = head;
		while (fast)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast)
			{
				fast = fast->next;
			}
		}
		return slow;

	}
};