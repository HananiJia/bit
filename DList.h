#pragma once

typedef int DataType;

typedef struct DListNode
{
	struct DListNode* _next;
	struct DListNode* _prev;
	DataType _data;
}DListNode;


DListNode* BuyDListNode(DataType x)
{
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	assert(node);
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;
}

DListNode* DListInit();
void DListDestory(DListNode* head);
void DListPrint(DListNode* head);

void DListPushBack(DListNode* head, DataType x);
void DListPushFront(DListNode* head, DataType x);
void DListPopBack(DListNode* head);
void DListPopFront(DListNode* head);

DListNode* DListFind(DListNode* head, DataType x);
void DListInsert(DListNode* pos, DataType x);
void DListErase(DListNode* pos);

void DListPrint(DListNode* head)
{
	DListNode* cur = head->_next;
	while (cur != head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}

	printf("HEAD\n");
}

DListNode* DListInit()
{
	DataType x = 0;
	DListNode* list = BuyDListNode(x);
	list->_next = list;
	list->_prev = list;

	return list;
}

void DListDestory(DListNode* head)
{
	DListNode* cur = head->_next;
	while (cur != head)
	{
		DListNode* next = cur->_next;
		free(cur);
		cur = next;
	}

	free(head);
}

void DListPushBack(DListNode* head, DataType x)
{
	/*assert(head);

	DListNode* tail = head->_prev;
	DListNode* newnode = BuyDListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;

	newnode->_next = head;
	head->_prev = newnode;*/

	DListInsert(head, x);
}

void DListPushFront(DListNode* head, DataType x)
{
	//assert(head);

	//DListNode* first = head->_next;
	//DListNode* newnode = BuyDListNode(x);
	//// head newnode first

	//head->_next = newnode;
	//newnode->_prev = head;
	//newnode->_next = first;
	//first->_prev = newnode;

	DListInsert(head->_next, x);

}

void DListPopBack(DListNode* head)
{
	//assert(head);
	//if (head->_next == head)
	//{
	//	return;
	//}

	//DListNode* tail = head->_prev;
	//DListNode* prev = tail->_prev;

	//// head   prev tail

	//prev->_next = head;
	//head->_prev = prev;
	//free(tail);

	DListErase(head->_prev);
}

void DListPopFront(DListNode* head)
{
	//assert(head);

	//if (head->_next == head)
	//	return;

	//DListNode* first= head->_next;
	//DListNode* next = first->_next;

	//// head first next
	//head->_next = next;
	//next->_prev = head;

	//free(first);
	DListErase(head->_next);
}

DListNode* DListFind(DListNode* head, DataType x)
{
	DListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
			return cur;

		cur = cur->_next;
	}

	return NULL;
}

void DListInsert(DListNode* pos, DataType x)
{
	assert(pos);
	DListNode* prev = pos->_prev;
	DListNode* newnode = BuyDListNode(x);

	// prev newnode pos

	prev->_next = newnode;
	newnode->_prev = prev;

	newnode->_next = pos;
	pos->_prev = newnode;
}

void DListErase(DListNode* pos)
{
	assert(pos);

	DListNode* prev = pos->_prev;
	DListNode* next = pos->_next;

	next->_prev = prev;
	prev->_next = next;
	free(pos);
}


void TestDList1()
{
	DListNode* list = DListInit();
	DListPushBack(list, 1);
	DListPushBack(list, 2);
	DListPushBack(list, 3);
	DListPushBack(list, 4);
	DListPushBack(list, 5);
	DListPrint(list);

	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPopBack(list);
	DListPrint(list);
}

void TestDList2()
{
	DListNode* list = DListInit();
	DListPushFront(list, 1);
	DListPushFront(list, 2);
	DListPushFront(list, 3);
	DListPushFront(list, 4);
	DListPushFront(list, 5);
	DListPrint(list);

	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPopFront(list);
	DListPrint(list);
}