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
		ListNode* cur1 = NULL;//���ǳ�����һ��
		ListNode* cur2 = NULL;//���Ƕ̵���һ��
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
		//cur2����Ƕ̵�����cur2�ǿ��˵Ļ��Ͳ�����
		//��ֵҪ���˳�����һ�������ֵ
		int carry = 0;//���λ��
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
        //��ʱ����ܻ����н�λ��
		while (carry != 0)//�����λ������0�Ǿ�˵���н�λ
		{
			//��ʱ��Ҫ��������������ǳ����Ǹ�����λ�ô洢��û�еĻ�����Ҫ����һ���ռ�
			if (cur1 == NULL)
			{
				//��ʱ�����Ҫ����һ���µĽڵ㣬Ϊ��������������Ҫ��ǰһ���ڵ�
				ListNode* Newcur = new ListNode(0);
				prev->next = Newcur;
				Newcur->next = NULL;
				Newcur->val = carry;
				carry = 0;
				cur1 = Newcur;
			}
			else
			{
				//����Ҫ�����µĽڵ�
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