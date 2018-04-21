#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef int DataType;


typedef struct Stack
{
	DataType* _array;
	size_t	_top; //栈顶 
	size_t	_end;

}Stack;

// 栈的实现接口 
void StackInit(Stack* s)
{
	
	s = (Stack*)malloc(sizeof(DataType)*5);
	s->_top = -1;
	s->_end = 0;

	

}
size_t StackSize(Stack* s)
{
	return s->_top ;
}


DataType StackTop(Stack* s)
{
	DataType ret = 0;
	ret = s->_array[s->_top];
	return ret;
	
}

int StackEmpty(Stack* s)
{
	if (s->_top == -1)
	{
		printf("栈为空\n");
		return -1;
	}
	else
		return 0;
}
void StackPop(Stack* s)
{
	DataType ret = 0;
	ret = StackEmpty(s);
	if (ret == -1)
	{
		return;
	}
	else
	{
		printf("%d", s->_array[s->_top]);
		s->_top = s->_top - 1;
	}
}
void StackPush(Stack* s, DataType x)
{


	s->_top = s->_top + 1;
	s->_array[s->_top] = x;

}
int main()
{
	Stack *stack=NULL;
	StackInit(stack);
	
	 StackPush(stack, 1);
	 StackPush(stack, 2);
	 StackPush(stack, 3);
	 StackPush(stack, 4);
	 StackPush(stack, 5);
	 StackPop(stack);

	return 0;
}