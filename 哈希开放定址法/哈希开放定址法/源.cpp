#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int KeyType;
typedef int ValueType;

enum Status
{
	EMPTY,
	EXITS,
	DELETE,
};

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	Status _status;
}HashNode;

typedef struct HashTable
{
	HashNode* _tables;
	size_t _size;
	size_t _N;
}HashTable;
void HashTableInit(HashTable *ht, size_t capacity);
//HashTable* HtCheck(HashTable *ht);
int HashTableInsert(HashTable* ht, KeyType key, ValueType value);
void HashTableDestory(HashTable* ht);
int HashTableRemove(HashTable* ht, KeyType key);
HashNode* HashTableFind(HashTable* ht, KeyType key);


void HashTableInit(HashTable *ht, size_t capacity)
{
	
	int i = 0;
	ht->_size = 0;
	ht->_N = capacity;
	ht->_tables = (HashNode*)malloc(sizeof(HashNode)*(ht->_N));
	
	for (i = 0; i < ht->_N; i++)
	{
		ht->_tables[i]._key = 0;
		ht->_tables[i]._value = 0;
		ht->_tables[i]._status = EMPTY;
	}
}
HashTable* HtCheck(HashTable *ht)
{
	HashTable Newht;
	int capacity1 = ht->_N;
	int i = 0;
	size_t capacity = ht->_N * 2;
	HashTableInit(&Newht, capacity);
	if (ht->_N < ht->_size * 7)
	{
		ht->_N = ht->_N * 2;

		for (i = 0; i < capacity1; i++)
		{
			if (ht->_tables[i]._status == EXITS)
			{
				HashTableInsert(&Newht, ht->_tables[i]._key, ht->_tables[i]._value);
			}

		}
		return &Newht;
	}
	else
	{
		return NULL;
	}
}
int HashTableInsert(HashTable* ht, KeyType key, ValueType value)
{
	assert(ht);
	HashTable *test = NULL;
	/*if (ht->_size == ht->_N)
	{
		printf("哈希表已满，插入失败\n");
	}*/
	test = HtCheck(ht);
	if (test != NULL)
	{
		ht = test;
	}
	int Index = 0;
	Index = key % (ht->_N);
	while (ht->_tables[Index]._status == EXITS)//if (ht->_tables[Index]._status == EXITS)说明这个位置不能放当前元素，需要找下一个位置
	{
		Index++;
			
		if (Index == ht->_N)//这里不会死循环，一定能找到一个值 因为你当前哈希表不是满的
		{
			Index = 0;
		}

	}
	    //总是要插入的  复用
		ht->_tables[Index]._key = key;
		ht->_tables[Index]._value = value;
		ht->_tables[Index]._status = EXITS;
		ht->_size++;
		return 0;
}
HashNode* HashTableFind(HashTable* ht, KeyType key)
{
	assert(ht);
	int Index = 0;
	int capacity=0;
	Index = key % (ht->_N);
	while (ht->_tables[Index]._key != key)
	{
		Index++;
		capacity++;
		if (capacity == ht->_N)
		{
			return NULL;
		}
	}
	return &ht->_tables[Index];
}
int HashTableRemove(HashTable* ht, KeyType key)
{
	assert(ht);
	int Index = 0;
	int capacity = 0;
	Index = key % (ht->_N);
	while (ht->_tables[Index]._key != key)
	{
		Index++;
		capacity++;
		if (capacity == ht->_N)
		{
			return -1;
		}
	}
	ht->_tables[Index]._status = DELETE;
	return 0;
}
void HashTableDestory(HashTable* ht)
{

}


int main()
{
	int i = 0;
	HashTable ht;
	HashNode *find = NULL;
	HashTableInit(&ht,53);
	for (i = 0; i < 50; i++)
	{
		HashTableInsert(&ht, i, i);
	}
	HashTableRemove(&ht, 49);
	for (i = 0; i < 50; i++)
	{

		find = HashTableFind(&ht, i);
		printf("key:%d value:%d status:%d\n", find->_key, find->_value, find->_status);
	}
	system("pause");
	return 0;
}