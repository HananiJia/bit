#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL || k == 0)//必须判断是否为空
		return NULL;
	ListNode *Fast = pListHead;
	ListNode *Slow = pListHead;
	int i = 0;
	while (i!=k-1)//k-1还是k和下边的while循环相对应一个是FAST->NEXT 一个是FAST
	{
		if (Fast->next== NULL)
			return NULL;
		else
			Fast = Fast->next;
		i++;
	}
	while (Fast->next!=NULL)
	{
		Fast = Fast->next;
		Slow = Slow->next;
	}
	return Slow;
}

int main()
{

}