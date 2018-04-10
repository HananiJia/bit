#pragma once

typedef int DataType;
typedef struct SListNode
{
	struct SListNode* _next;
	DataType          _data;
}SListNode;

SListNode* BuySListNode(DataType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;

	return node;
}

void SListPushBack(SListNode** ppHead, DataType x)
{
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		SListNode* cur = *ppHead;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}

		cur->_next = BuySListNode(x);
	}
}

void SListPushFront(SListNode** ppHead, DataType x)
{
	if (*ppHead == NULL)
	{
		*ppHead = BuySListNode(x);
	}
	else
	{
		SListNode* newNode = BuySListNode(x);
		newNode->_next = *ppHead;
		*ppHead = newNode;
	}
}

void SListPopBack(SListNode** ppHead)
{
	// 1.空
	// 2.一个
	// 3.多个
	if(*ppHead == NULL)
	{
		return;
	}
	else if ((*ppHead)->_next == NULL)
	{
		free(*ppHead);
		*ppHead = NULL;
	}
	else
	{
		SListNode* prev = NULL, *cur = *ppHead;
		while (cur->_next)
		{
			prev = cur;
			cur = cur->_next;
		}

		free(cur);
		prev->_next = NULL;
	}
}

void SListPopFront(SListNode** ppHead)
{
	if (*ppHead == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = (*ppHead)->_next;
		free(*ppHead);
		*ppHead = next;
	}
}

void SListDestory(SListNode** ppHead)
{
	SListNode* cur = *ppHead;
	while(cur)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	*ppHead = NULL;
}

void SListPrint(SListNode* pHead)
{
	SListNode* cur = pHead;
	//while (cur != NULL)
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

SListNode* SListFind(SListNode* pHead, DataType x)
{
	SListNode* cur = pHead;
	while(cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

void SListInsert(SListNode** ppHead, SListNode* pos, DataType x)
{
	assert(pos && *ppHead);
	// 1.头
	// 2.中间
	if(pos == *ppHead)
	{
		SListPushFront(ppHead, x);
	}
	else
	{
		SListNode* newnode = BuySListNode(x);
		SListNode* prev = *ppHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}

		// prev newnode pos
		prev->_next = newnode;
		newnode->_next = pos;
	}
}

void SListErase(SListNode** ppHead, SListNode* pos)
{
	assert(pos && *ppHead);

	if ((*ppHead) == pos)
	{
		SListPopFront(ppHead);
	}
	else if (pos->_next == NULL)
	{
		SListPopBack(ppHead);
	}
	else
	{
		SListNode* prev = *ppHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}

		prev->_next = pos->_next;
		free(pos);
	}
}

void TestSList1()
{
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);

	SListPopFront(&list);
	SListPopFront(&list);
	SListPopFront(&list);
	SListPopFront(&list);
	SListPopFront(&list);
	SListPrint(list);

	SListPushFront(&list, 1);
	SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPrint(list);

	SListDestory(&list);

	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(list);
}

void TestSList2()
{
	SListNode* pos;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);

	pos = SListFind(list, 3);
	SListInsert(&list, pos, 30);
	SListPrint(list);

	SListInsert(&list, list, 10);
	SListPrint(list);

	pos = SListFind(list, 3);
	SListErase(&list, pos);

	pos = SListFind(list, 10);
	SListErase(&list, pos);

	pos = SListFind(list, 4);
	SListErase(&list, pos);

	SListPrint(list);
}

////////////////////////////////////////////////
// 链表面试题

void PrintTailToHead(SListNode* head)
{
	SListNode* end = NULL;

	while (end != head)
	{
		SListNode* cur = head;
		while (cur->_next != end)
		{
			cur = cur->_next;
		}

		printf("%d ", cur->_data);

		end = cur;
	}

	printf("\n");
}

void PrintTailToHeadR(SListNode* head)
{
	if(head == NULL)
		return;

	PrintTailToHeadR(head->_next);
	printf("%d ", head->_data);
}

void TestPrintTailToHead()
{
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);
	
	PrintTailToHead(list);
	PrintTailToHeadR(list);
	printf("\n");
}

void DelNode(SListNode* pos)
{
	SListNode* next;
	assert(pos && pos->_next);

	// 替换法删除
	next = pos->_next;
	pos->_data = next->_data;
	pos->_next = next->_next;
	free(next);
}

void TestDelNode()
{
	SListNode* pos = NULL;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);

	pos = SListFind(list, 3);
	DelNode(pos);
	SListPrint(list);
}

void InsertNode(SListNode* pos, DataType x)
{
	SListNode* tmp;
	assert(pos);

	tmp = BuySListNode(pos->_data);
	tmp->_next = pos->_next;
	pos->_next = tmp;

	pos->_data = x;
}

void TestInsertNode()
{
	SListNode* pos = NULL;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);

	pos = SListFind(list, 3);
	InsertNode(pos, 30);
	SListPrint(list);
}


SListNode* JosephCycle(SListNode* head, int k)
{
	SListNode* tail = head, *cur = head;
	if(head == NULL)
		return NULL;

	// 构成环
	while (tail->_next)
		tail = tail->_next;
	tail->_next = head;

	while (cur->_next != cur)
	{
		SListNode* next;
		int count = k;
		while (--count)
			cur = cur->_next;

		next = cur->_next;
		cur->_data = next->_data; 
		cur->_next = next->_next;

		free(next);
	}

	return cur;
}

void TestJosephCycle()
{
	SListNode* pos = NULL;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);

	pos = JosephCycle(list, 5);
	printf("幸存者:%d\n", pos->_data);
}

SListNode* ReverseList1(SListNode* head)
{
	SListNode* n1, *n2, *n3;
	if (head == NULL || head->_next == NULL)
		return head;

	n1 = head;
	n2 = n1->_next;
	n3 = n2->_next;

	while (n2)
	{
		n2->_next = n1;

		n1 = n2;
		n2 = n3;

		if(n3)
			n3 = n3->_next;
	}

	head->_next = NULL;
	head = n1;

	return head;
}

SListNode* ReverseList2(SListNode* head)
{
	SListNode* newhead = NULL;
	SListNode* cur = head;
	while (cur)
	{
		SListNode* tmp = cur;
		cur = cur->_next;

		// 头插
		tmp->_next = newhead;
		newhead = tmp;
	}

	return newhead;
}

void TestReverseList()
{
	SListNode* newlist;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);

	newlist = ReverseList2(list);
	SListPrint(newlist);
}

void BubbleSortList(SListNode* head)
{
	SListNode* cur, *next;
	SListNode* tail = NULL;
	if (head == NULL || head->_next == NULL)
		return;

	while (tail != head->_next)
	{
		int flag = 0;
		cur = head;
		next = cur->_next;
		while (next != tail)
		{
			if (cur->_data > next->_data)
			{
				DataType tmp = cur->_data;
				cur->_data = next->_data;
				next->_data = tmp;

				flag = 1;
			}
			cur = cur->_next;
			next = next->_next;
		}

		if (flag == 0)
		{
			break;
		}

		tail = cur;
	}
}


void TestBubbleSortList()
{
	//SListNode* newlist;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 20);
	SListPushBack(&list, 31);
	SListPushBack(&list, 4);
	SListPushBack(&list, 50);
	SListPushBack(&list, 16);
	SListPushBack(&list, 7);

	BubbleSortList(list);

	SListPrint(list);
}

SListNode* MergeList(SListNode* list1, SListNode* list2)
{
	SListNode* list, *tail;
	if (list1 == NULL)
		return list2;

	if (list2 == NULL)
		return list1;

	if (list1->_data < list2->_data)
	{
		list = list1;
		list1 = list1->_next;;
	}
	else 
	{
		list = list2;
		list2 = list2->_next;
	}

	tail = list;
	while (list1 && list2)
	{
		if (list1->_data < list2->_data)
		{
			tail->_next = list1;
			list1 = list1->_next;
		}
		else
		{
			tail->_next = list2;
			list2 = list2->_next;
		}

		tail = tail->_next;
	}

	if (list1)
		tail->_next = list1;

	if (list2)
		tail->_next = list2;

	return list;
}

void TestMergeList()
{
	SListNode* newlist;
	SListNode* list1 = NULL, *list2 = NULL;
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 5);
	SListPushBack(&list1, 9);

	SListPushBack(&list2, 2);
	SListPushBack(&list2, 3);
	SListPushBack(&list2, 6);
	SListPushBack(&list2, 7);
	SListPushBack(&list2, 8);
	SListPushBack(&list2, 9);
	
	newlist = MergeList(list1, list2);
	SListPrint(newlist);
}

SListNode* FindMidNode(SListNode* pHead)
{
	SListNode* fast, *slow;

	if (pHead == NULL || pHead->_next == NULL)
		return pHead;

	slow = pHead;
	fast = slow->_next->_next;

	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
		if (fast)
			fast = fast->_next;
	}
	
	return slow;
}



void TestFindMidNode()
{
	//SListNode* newlist;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);

	printf("%d\n", FindMidNode(list)->_data);
}

SListNode* FindTailK(SListNode* pHead, int k)
{
	SListNode* fast, *slow;
	fast = slow = pHead;

	while (k--)
	{
		if (fast == NULL)
			return NULL;

		fast = fast->_next;
	}

	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}

	return slow;
}

void TestFindTailK()
{
	//SListNode* newlist;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);

	printf("%d\n", FindTailK(list, 8)->_data);
}

SListNode* IsCycle(SListNode* pHead)
{
	SListNode* slow, * fast;
	slow = fast = pHead;

	while (fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;

		if (fast == slow)
		{
			return fast;
		}
	}

	return NULL;
}


SListNode* GetEntry(SListNode* pHead, SListNode* meet)
{
	while (pHead != meet)
	{
		pHead = pHead->_next;
		meet = meet->_next;
	}

	return meet;
}

void TestCycle()
{
	SListNode* pos, *tail, *meet;
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);

	pos = SListFind(list, 5);
	tail = SListFind(list, 8);
	tail->_next = pos;

	meet = IsCycle(list);
	printf("entry:%d\n", GetEntry(list, meet)->_data);
}

SListNode* GetCrossNode(SListNode* list1, SListNode* list2)
{
	int len1 = 0, len2 = 0, gap = 0;
	SListNode* cur1 = list1, *cur2 = list2;
	SListNode* shortlist, *longlist;
	while(cur1)
	{
		++len1;
		cur1 = cur1->_next;
	}

	while (cur2)
	{
		++len2;
		cur2 = cur2->_next;
	}

	longlist = list1;
	shortlist = list2;
	if (len1 < len2)
	{
		longlist = list2;
		shortlist = list1;
	}

	gap = abs(len1-len2);
	while (gap--)
		longlist = longlist->_next;

	while (longlist != shortlist)
	{
		longlist = longlist->_next;
		shortlist = shortlist->_next;
	}
	
	return shortlist;
}

void TestGetCross()
{
	SListNode* pos1, *pos2;
	SListNode* list1 = NULL, *list2 = NULL;
	SListPushBack(&list1, 1);
	SListPushBack(&list1, 3);
	SListPushBack(&list1, 5);
	SListPushBack(&list1, 9);

	SListPushBack(&list2, 2);
	SListPushBack(&list2, 4);
	SListPushBack(&list2, 6);
	SListPushBack(&list2, 7);
	SListPushBack(&list2, 8);
	SListPushBack(&list2, 10);
	
	pos1 = SListFind(list1, 9);
	pos2 = SListFind(list2, 8);
	pos1->_next = pos2;

	printf("%d\n", GetCrossNode(list1, list2)->_data);
}


typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;


ComplexNode* CopyList(ComplexNode* list);
