#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//实现动态顺序表
typedef int DataType;

typedef struct SeqList
{
	DataType* _a;
	size_t _size;	// 有效数据个数 
	size_t _capacity;	// 容量 
}SeqList;

int CheckCapacity(SeqList *pSeq)
{

	if (pSeq->_size >= pSeq->_capacity)
	{

		DataType *List = NULL;
		List = (DataType*)realloc(pSeq->_a, sizeof(DataType)* 100);

		if (List != NULL)
		{
			pSeq->_a = List;
			pSeq->_capacity = pSeq->_capacity + (sizeof(DataType)* 100);
			return 0;

		}
		else
		{
			printf("空间增加失败\n");
			return -1;
		}
	}
	return 0;
}

void SeqPrint(SeqList* pSeq)//输出当前链表
{
	assert(pSeq);
	if (pSeq->_size == 0)
	{
		printf("顺序链表没有数据\n");
		return;
	}
	size_t i = 0;
	for (; i < pSeq->_size; i++)
	{
		printf("%d\n", pSeq->_a[i]);
	}
	printf("\n");
}
void SeqInit(SeqList* pSeq)//初始化当前链表
{
	assert(pSeq);
	pSeq->_a = NULL;
	pSeq->_size = 0;
	pSeq->_capacity = 0;
}
void SeqDestory(SeqList* pSeq)//销毁当前链表
{
	assert(pSeq);
	pSeq->_capacity = 0;
	pSeq->_size = 0;
	free(pSeq->_a);
	pSeq->_a = NULL;
}

void SeqPushBack(SeqList* pSeq, DataType x)//从链表尾部插入数据
{
	assert(pSeq);
	size_t ret = 0;
	ret = CheckCapacity(pSeq);
	if (ret == -1)
	{
		printf("空间不足扩展失败\n");
	}
	else
	{
		pSeq->_a[pSeq->_size] = x;
		pSeq->_size++;
	}
}
void SeqPopBack(SeqList* pSeq)//从链表尾部删除数据
{
	assert(pSeq);
	pSeq->_a[pSeq->_size] = 0;
	pSeq->_size--;
}
void SeqPushFront(SeqList* pSeq, DataType x)//从头部插入数据
{
	assert(pSeq);
	size_t ret = 0;
	size_t i = 0;
	ret = CheckCapacity(pSeq);
	if (ret == -1)
	{
		printf("空间不足扩展失败\n");
	}
	else
	{
		i = pSeq->_size;
		for (; i > 0; i--)
		{
			pSeq->_a[i] = pSeq->_a[i - 1];
		}
		pSeq->_a[0] = x;
		pSeq->_size++;
	}
}
void SeqPopFront(SeqList* pSeq)//从头部删除数据
{
	assert(pSeq);
	size_t i = 0;
	for (; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;

}

void SeqInsert(SeqList* pSeq, size_t pos, DataType x)//在指定pos位置插入数据
{
	assert(pSeq);
	size_t i = 0;
	size_t ret = 0;
	ret = CheckCapacity(pSeq);
	if (ret == -1)
	{
		printf("空间不足插入失败\n");

	}
	else
	{
		for (i = pSeq->_size; i>pos; i--)
		{
			pSeq->_a[i] = pSeq->_a[i - 1];
		}
		pSeq->_a[pos] = x;
		pSeq->_size++;
	}

}
void SeqErase(SeqList* pSeq, size_t pos)//在指定位置删除数据
{
	assert(pSeq);
	size_t i = 0;
	for (i = pos - 1; i < pSeq->_size; i++)
	{
		pSeq->_a[i] = pSeq->_a[i + 1];
	}
	pSeq->_size--;
}

int SeqFind(SeqList* pSeq, DataType x)//在链表中寻找某个指定的数值
{
	assert(pSeq);
	size_t i = 0;
	for (; i < pSeq->_size; i++)
	{
		if (pSeq->_a[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}
void SeqAt(SeqList* pSeq, size_t pos, DataType x)//替换指定pos位置的数据
{
	assert(pSeq);
	if (pos >= pSeq->_size)
	{
		printf("插入位置不在当前顺序表中\n");
	}
	else
	{

		pSeq->_a[pos - 1] = x;

	}
}

void BubbleSort(SeqList* pSeq)//对当前链表进行冒泡排序
{
	assert(pSeq);
	size_t i = 0;
	size_t j = 0;
	size_t temp = 0;
	for (; i < pSeq->_size; i++)
	{
		for (; j < pSeq->_size - 1 - i; j++)
		{
			if (pSeq->_a[j]>pSeq->_a[j + 1])
			{
				temp = pSeq->_a[j];
				pSeq->_a[j] = pSeq->_a[j + 1];
				pSeq->_a[j + 1] = temp;
			}
		}
	}

}
void SelectSort(SeqList* pSeq)//选择排序
{
	assert(pSeq);
	size_t min = 0;
	size_t i = 0;
	size_t j = 0;
	size_t temp = 0;
	int k = 0;
	for (; i < pSeq->_size; i++)
	{

		min = i;
		k = pSeq->_a[i];
		for (j = i + 1; j < pSeq->_size; j++)
		{
			if (pSeq->_a[j] < k)
			{
				min = j;
				k = pSeq->_a[j];
			}
		}
		if (min != i)
		{
			temp = pSeq->_a[i];
			pSeq->_a[i] = pSeq->_a[min];
			pSeq->_a[min] = temp;
		}

	}

}
int BinarySearch(SeqList* pSeq, DataType x)//二分查找
{
	assert(pSeq);
	size_t left = 0;
	size_t right = pSeq->_size - 1;
	size_t mid = 0;
	BubbleSort(pSeq);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (pSeq->_a[mid] == x)
		{
			return mid + 1;
		}
		else
		{
			if (pSeq->_a[mid] > x)
			{
				right = mid - 1;
			}
			else
			{
				if (pSeq->_a[mid] < x)
				{
					left = mid + 1;
				}
			}
		}
	}
	return -1;

}


int main()
{
	SeqList s;
	SeqInit(&s);
	SeqPushBack(&s, 1);
	SeqPushBack(&s, 2);
	SeqPushBack(&s, 3);
	SeqPushBack(&s, 4);
	SeqPushBack(&s, 5);
	SeqPushFront(&s, 6);
	SeqPrint(&s);
	SeqPopBack(&s);
	SeqPrint(&s);
	SeqPushFront(&s, 9);
	SeqPrint(&s);
	SeqPopFront(&s);
	SeqPrint(&s);
	SeqInsert(&s, 3, 9);
	SeqPrint(&s);
	SeqErase(&s, 5);
	SeqPrint(&s);
	printf("你要找的数在该顺序表中的位置是第%d位!\n", SeqFind(&s, 9));
	SeqAt(&s, 1, 1);
	SeqPrint(&s);
	SelectSort(&s);
	printf("排序后的顺序表为：\n");
	BubbleSort(&s);
	SeqPrint(&s);
	printf("\n");
	printf("你要找的数在该顺序表中的位置是第%d位!\n", BinarySearch(&s, 9));
	SeqDestory(&s);
	SeqPrint(&s);
	system("pause");
	return 0;
}