#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {
//		if (head == NULL)
//			return NULL;
//		ListNode* n1 = head;
//		ListNode* n2 = n1->next;
//		if (n2 == NULL)
//			return head;
//		ListNode* n3 = n2->next;
//		n1->next = NULL;
//		while (n3)
//		{
//			n2->next = n1;
//			n1 = n2;
//			n2 = n3;
//			n3 = n3->next;
//		}
//		n2->next = n1;
//		return n2;
//	}
//};
 
 class Solution {
 public:
	 ListNode* reverseList(ListNode* head) {

	 }
 };