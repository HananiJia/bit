#pragme once
#include<iostream>
#include<assert.h>
typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	ListNode*_next;
	ListNode* _prev;
	ListNode(DataType x)
		:_data(x)
		, _next(NULL)
		, _prev(NULL)
	{}
};
class List
{
	typedef ListNode Node;
public:
	List()
	{
		_head = new Node(DataType());//ÄäÃû¶ÔÏó
		_head->_next = _head;
		_head->_prev = _head;
	}
	~List()
	{
		
	}

	List(const List& l)
	{
		_head = new Node(DataType());
		_head->_next = _head;
		_head->_prev = _head;
		Node* cur = l._head->_next;
		while (cur != l._head)
		{

		}
	}
	List& operator=(const List& l)
	{
		swap(_head, l._head);
		return *this;
	}
	void PushBack(DataType x);
	void PopBack()
	{
		Erase(_head->_prev);
	}
	void PushFront(DataType x);
	void PopFrint();
	void Insert(Node* pos, DataType x)
	{
		Node* prev = pos->_prev;
		Node *newnode = new Node(x);
		pos->_prev = newnode;
		newnode->_next = pos;
		prev->_next = newnode;
		newnode->_prev = prev;
	}
	void Erase(Node* pos)
	{ 
		assert(pos != _head);
		Node* prev = pos->_prev;
		Node* next = pos->_next;
		delete pos;
		prev->_next = next;
		next->_prev = prev;

		
	}
    
	bool Empty()
	{
		return _head->_next == _head;
	}
private:
	Node* _head;
};