#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// class SortListNode{
// public:
//	 bool operator()(ListNode* a, ListNode* b)
//	 {
//		 if (a->val < b->val)
//			 return true;
//		 return false;
//	 }
//
// };
//class Solution {
//public:
//	ListNode* sortList(ListNode* head) {
//		if (head == NULL||head->next==NULL)
//			return head;
//		vector<ListNode*> a;
//		ListNode* cur = head;
//		while (cur)
//		{
//			a.push_back(cur);
//			cur = cur->next;
//		}
//		sort(a.begin(), a.end(),SortListNode());
//		for (int i = 0; i < a.size() - 1; i++)
//		{
//			a[i]->next = a[i + 1];
//		}
//		a[a.size() - 1]->next = NULL;
//		return a[0];
//	}
//};
 //class Solution {
 //public:
	// ListNode* sortList(ListNode* head) {
	//	 if (head == NULL || head->next == NULL) return head;
	//	 // ¹é²¢ÅÅÐò
	//	 return MergeSort(head);
	// }
	// ListNode* MergeSort(ListNode *head){
	//	 if (head == NULL || head->next == NULL) return head;
	//	 ListNode *Mid = findMid(head);
	//	 ListNode *MidNext = Mid->next;
	//	 Mid->next = NULL;
	//	 head = MergeSort(head);
	//	 MidNext = MergeSort(MidNext);
	//	 return Merge(head, MidNext);
	// }
	// ListNode *findMid(ListNode *head){
	//	 ListNode *fast = head->next, *slow = head;//fast = head»á³ö´í
	//	 while (fast && fast->next){
	//		 fast = fast->next->next;
	//		 slow = slow->next;
	//	 }
	//	 return slow;
	// }
	// ListNode* Merge(ListNode *a, ListNode *b){
	//	 if (a == NULL) return b;
	//	 if (b == NULL) return a;

	//	 if (a->val < b->val){
	//		 a->next = Merge(a->next, b);
	//		 return a;
	//	 }
	//	 else{
	//		 b->next = Merge(b->next, a);
	//		 return b;

	//	 }
	// }
 //};

 class Solution {
 public:
	 ListNode* sortList(ListNode* head) {
		 if (head == NULL || head->next == NULL)
			 return head;
		 return MergeSort(head);
	 }
	 ListNode* MergeSort(ListNode* head)
	 {
		 if (head == NULL || head->next == NULL)
			 return head;
		 ListNode* Mid = FindMid(head);
		 ListNode* MidNext = Mid->next;
		 Mid->next = NULL;
		head= MergeSort(head);
		MidNext= MergeSort(MidNext);
		 return Merge(head, MidNext);
	 }
	 ListNode* Merge(ListNode* Mid, ListNode* MidNext)
	 {
		 if (Mid == NULL)
			 return MidNext;
		 if (MidNext == NULL)
			 return Mid;
		 if (Mid->val < MidNext->val)
		 {
			 Mid->next = Merge(Mid->next, MidNext);
			 return Mid;
		 }
		 else
		 {
			 MidNext->next = Merge(MidNext->next,Mid);
			 return MidNext;
		 }
	 }
	 ListNode* FindMid(ListNode* head)
	 {
		 ListNode* slow = head;
		 ListNode* fast = head->next;
		 while (fast&&fast->next)
		 {
			 slow = slow->next;
			 fast = fast->next->next;
		 }
		 return slow;
	 }
 };

int main()
{
	ListNode *n1=new ListNode(4);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	Solution A;
	ListNode* cur = A.sortList(n1);
	while (cur)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
	system("pause");
	return 0;
}