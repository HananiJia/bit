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
	 ListNode *detectCycle(ListNode *head) {
		 if (head == NULL || head->next == NULL)
			 return NULL;
		 ListNode* slow = head;
		 ListNode* fast = head;
		 ListNode* meet = NULL;
		 int flag = 0;
		 while (fast)
		 {
			 fast = fast->next;
			 if (fast)
				 fast = fast->next;
			 else
				 return NULL;
			 slow = slow->next;
			 if (fast == slow)
			 {
				 meet = fast;
				 flag = 1;
				 break;
			 }
		 }//出来有两种情况
		 if (flag == 0)
			 return NULL;
		 ListNode* cur = head;
		 while (meet != cur)
		 {
			 cur = cur->next;
			 meet = meet->next;
		 }
		 return cur;
	 }
 };