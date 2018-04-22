#pragma once

typedef struct Pos
{
	int _row; // 行
	int _col; // 列
}Pos;

typedef BTNode* STDataType;

typedef struct Stack
{	
	STDataType* _st;
	size_t _size;
	size_t _capacity;
}Stack;

void StackInit(Stack* s, size_t capacity);
void StackDestory(Stack* s);
void StackPush(Stack* s, STDataType x);
void StackPop(Stack* s);
STDataType StackTop(Stack* s);
size_t StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackCopy(Stack* src, Stack* dst);

void StackCopy(Stack* src, Stack* dst)
{
	assert(src && dst);

	if (src->_size == 0)
	{
		dst->_size = 0;
	}
	else
	{
		if (src->_size > dst->_capacity)
		{
			dst->_st = (STDataType*)realloc(dst->_st, src->_size);
			dst->_capacity = src->_size;
		}
		
		dst->_size = src->_size;
		memcpy(dst->_st, src->_st, sizeof(STDataType)*src->_size);
	}
}


void StackInit(Stack* s, size_t capacity)
{
	assert(s && capacity > 0);
	s->_st = (STDataType*)malloc(sizeof(STDataType)*capacity);
	assert(s->_st);
	s->_size = 0;
	s->_capacity = capacity;
}

void StackPush(Stack* s, STDataType x)
{
	assert(s);
	if (s->_size == s->_capacity)
	{
		s->_capacity *= 2;
		s->_st = (STDataType*)realloc(s->_st, sizeof(STDataType)*s->_capacity);
	}

	s->_st[s->_size++] = x;
}

void StackPop(Stack* s)
{
	assert(s && s->_size);

	--s->_size;
}

STDataType StackTop(Stack* s)
{
	assert(s && s->_size);

	return s->_st[s->_size-1];

}
size_t StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}

// 空返回0，否则返回非零
int StackEmpty(Stack* s)
{
	return s->_size;
}

//void TestStack()
//{
//	Stack s;
//	StackInit(&s, 3);
//
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	printf("%d ", StackTop(&s));
//	StackPop(&s);
//
//	StackPush(&s, 4);
//
//	printf("%d ", StackTop(&s));
//	StackPop(&s);
//
//	StackPush(&s, 5);
//	StackPush(&s, 6);
//
//	while (StackEmpty(&s) != 0)
//	{
//		printf("%d ", StackTop(&s));
//		StackPop(&s);
//	}
//
//	printf("\n");	
//
//}