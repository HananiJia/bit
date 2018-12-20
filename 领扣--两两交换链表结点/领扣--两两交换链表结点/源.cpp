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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* n1 = head;
		ListNode* n2 = n1->next;
		ListNode* n3;
		n1->next = n2->next;
		n2->next = n1;
		n3 = n1;
		head = n2;
		while (n1->next&&n1->next->next)
		{
			n1 = n1->next;
			n2 = n1->next;
			n1->next = n2->next;
			n2->next = n1;
			n3->next = n2;
			n3 = n1;
		}
		return head;
	}
};


int main()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	n4->next = NULL;
	Solution A;
	ListNode* cur=A.swapPairs(n1);
	while (cur)
	{
		cout << cur->val << endl;
		cur = cur->next;
	}
	system("pause");
	return 0;
}