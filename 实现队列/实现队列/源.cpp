#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DataType;

typedef struct QueueNode
{
	DataType _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* q)
{
	q->_head = (QueueNode*)malloc(sizeof(QueueNode));
	q->_tail = q->_head;
	q->_tail->_next = NULL;
	
}
void QueuePush(Queue* q, DataType x)
{
	QueueNode *NewNode;
	NewNode = (QueueNode*)malloc(sizeof(QueueNode));
	NewNode->_data = x;
	q->_tail->_next = NewNode;
	NewNode->_next = NULL;
	q->_tail = NewNode;
}
void QueuePop(Queue* q)
{
	int ret = 0;
	ret = QueueEmpty(q);
	QueueNode *cur;
	if (ret == -1)
	{
		printf("队列为空不能出队\n");
	}
	else
	{
		cur = q->_head->_next;
		printf("%d", cur->_data);
		q->_head->_next = cur->_next;
		free(cur);
		

	}
}
DataType QueueFront(Queue* q)
{
	return q->_head->_next->_data;
}
DataType QueueBack(Queue* q)
{
	return q->_tail->_data;
}
size_t QueueSize(Queue* q)
{
	return (q->_tail - q->_head);
}
int QueueEmpty(Queue* q)
{
	if (q->_head == q->_tail)
		return -1;
	else
	return 0;
}