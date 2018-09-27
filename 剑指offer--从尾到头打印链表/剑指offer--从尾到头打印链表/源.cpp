#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> array;
		if (head == NULL)
			return array;
		if (head->next == NULL)
		{
			array.push_back(head->val);
			return array;
		}
		ListNode *n1=head;
		ListNode *n2 = n1->next;
		ListNode *n3 = n2->next;
		n1->next = NULL;
		while (n2 != NULL)
		{
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3 == NULL)
				break;
			n3 = n3->next;
		}
		
		while (n1)
		{
			array.push_back(n1->val);
			n1 = n1->next;
		}
		return array;
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> array;
		if (head == NULL)
			return array;
		if (head->next == NULL)
		{
			array.push_back(head->val);
			return array;
		}
		stack<int> s;
		ListNode *now = head;
		while (now)
		{
			s.push(now->val);
			now = now->next;
		}
		while (!s.empty())
		{
			array.push_back(s.top());
			s.pop();
		}
		return array;
	}
};
vector<int> array;
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
	
		if (head == NULL)
			return;
		printListFromTailToHead(head->next);
		array.push_back(head->val);
	
	}
};