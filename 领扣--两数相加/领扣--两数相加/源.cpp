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
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		int numl1 = 0;
//		int numl2 = 0;
//		int num1 = 0;
//		int num2 = 0;
//		ListNode* n1 = l1;
//		ListNode* n2 = l2;
//		while (n1)
//		{
//			num1 += n1->val*pow(10, numl1);
//			numl1++;
//			n1 = n1->next;
//		}
//		while (n2)
//		{
//			num2 += n2->val*pow(10, numl2);
//			numl2++;
//			n2 = n2->next;
//		}
//		int num = num1 + num2;
//		ListNode* root = (ListNode*)malloc(sizeof(ListNode));
//		ListNode* prev = root;
//		root->val = num % 10;
//		root->next = NULL;
//		num = num / 10;
//		while (num > 9)
//		{
//			ListNode* now = (ListNode*)malloc(sizeof(ListNode));
//			now->val = num % 10;
//			now->next = NULL;
//			prev->next = now;
//			prev = now;
//			num = num / 10;
//		}
//		if (num != 0)
//		{
//
//			ListNode* now = (ListNode*)malloc(sizeof(ListNode));
//			now->val = num;
//			now->next = NULL;
//			prev->next = now;
//		}
//		return root;
//		
//	}
//};

 //class Solution {
 //public:
	// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	//	 int numl1 = 0;
	//	 int numl2 = 0;
	//	ListNode* n1 = l1;
	//	 ListNode* n2 = l2;
	//	 while (n1)
	//	 {
	//		 numl1++;
	//		 n1 = n1->next;
	//	 }
	//	 while (n2)
	//	 {
	//		 numl2++;
	//		 n2 = n2->next;
	//	 }
	//	 ListNode* root = NULL;
	//	 ListNode* cur = NULL;
	//	 ListNode* ret = NULL;
	//	 if (numl1 > numl2)
	//	 {
	//		 root = l1;
	//		 cur = l2;
	//		 ret = l1;
	//	 }
	//	 else
	//	 {
	//		 root = l2;
	//		 cur = l1;
	//		 ret = l2;
	//	 }
	//	 int carry = 0;
	//	 ListNode* prev=NULL;
	//	 while (cur)
	//	 {
	//		 int num = root->val + cur->val+carry;
	//		 if (num >= 10)
	//		 {
	//			 carry = num - 9;
	//			 root->val = num - 10;
	//		 }
	//		 else
	//		 {
	//			 root->val = num;
	//			 carry = 0;
	//		 }
	//		 cur = cur->next;
	//		 prev = root;
	//		 root = root->next;
	//	 }
	//	 while (carry != 0)
	//	 {
	//		 if (root == NULL)
	//		 {
	//			 ListNode* root = new ListNode(0);
	//		 }
	//		 int num = root->val + carry;
	//		 if (num >= 10)
	//		 {
	//			 carry = num - 9;
	//			 root->val = num - 10;
	//		 }
	//		 else
	//		 {
	//			 root->val = num;
	//			 carry = 0;
	//		 }
	//		 prev->next = root;
	//		 prev = root;
	//		 root = root->next;
	//	 }
	//	 return ret;

	// }
 //};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int num1 = 0;
		int num2 = 0;
		ListNode* n1 = l1;
		ListNode* n2 = l2;
		while (n1)
		{
			num1++;
			n1 = n1->next;
		}
		while (n2)
		{
			num2++;
			n2 = n2->next;
		}
		ListNode* cur1 = NULL;//这是长的那一条
		ListNode* cur2 = NULL;//这是短的那一条
		if (num1 > num2)
		{
			cur1 = l1;
			cur2 = l2;
		}
		else
		{
			cur1 = l2;
			cur2 = l1;
		}
		ListNode* ret = cur1;
		ListNode* prev = NULL;
		//cur2存的是短的所以cur2是空了的话就不走了
		//赋值要给了长的那一个链表的值
		int carry = 0;//存进位的
		while (cur2)
		{
			int num = cur1->val + cur2->val + carry;
			if (num >= 10)
			{
				cur1->val = num - 10;
				carry = 1;
			}
			else
			{
				carry = 0;
				cur1->val = num;
			}
			prev = cur1;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
        //这时候可能还是有进位的
		while (carry != 0)//如果进位不等于0那就说明有进位
		{
			//这时候要分两种情况，就是长的那个还有位置存储，没有的话就需要开辟一个空间
			if (cur1 == NULL)
			{
				//这时候就需要开辟一个新的节点，为了链接起来就需要有前一个节点
				ListNode* Newcur = new ListNode(0);
				prev->next = Newcur;
				Newcur->next = NULL;
				Newcur->val = carry;
				carry = 0;
				cur1 = Newcur;
			}
			else
			{
				//不需要开辟新的节点
				int num = cur1->val + carry;
				if (num >= 10)
				{
					cur1->val = num - 10;
					carry = 1;
				}
				else
				{
					cur1->val = num;
					carry = 0;
				}
			}
			prev = cur1;
			cur1 = cur1->next;
		}
		return ret;
	}
};


int main()
{
	ListNode* l1 = new ListNode(0);
	l1->next = NULL;
	l1->val = 5;
	ListNode* l2 = new ListNode(0);
	l2->next = NULL;
	l2->val = 5;
	Solution a;
	ListNode* ret=a.addTwoNumbers(l1, l2);
	cout << ret->val << endl;
	system("pause");
	return 0;
}