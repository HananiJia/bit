#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef struct BitMap
{
	size_t* _bits;
	size_t _range;
}BitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, size_t x);//0变成1
void BitMapReset(BitMap* bm, size_t x);//1变成0
// x存在返回0，不存在返回-1 
int BitMapTest(BitMap* bm, size_t x);

void BitMapInit(BitMap* bm, size_t range)
{
	assert(bm);
	bm->_range = range;
	bm->_bits = (size_t*)malloc(sizeof(size_t)*bm->_range / 8 + 1);//这两个函数分配的操作的都是字节
	memset(bm->_bits, 0, sizeof(size_t)*bm->_range / 8 + 1);
	return;
}

void BitMapSet(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x/8;
	size_t num = x % 32;
	bm->_bits[index] |= ((size_t)1 << num);
}

void BitMapReset(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x / 8;
	size_t num = x % 32;
	bm->_bits[index] &= ~((size_t)1 << num);
	return;
}

int BitMapTest(BitMap* bm, size_t x)
{
	assert(bm);
	size_t index = x / 8;
	size_t num = x % 32;
	return ((bm->_bits[index] >> num) & 1);
}

int main()
{
	BitMap bm;
	int set = 0;
	BitMapInit(&bm, 100);
	BitMapSet(&bm, 1);
	BitMapSet(&bm, 11);
	BitMapSet(&bm, 10);
	BitMapReset(&bm, 11);
	printf("%d",BitMapTest(&bm, 1));
	printf("%d", BitMapTest(&bm, 11));
	system("pause");
	return 0;


}