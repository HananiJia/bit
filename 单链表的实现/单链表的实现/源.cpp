#define _CRT_SECURE_NO_WARNINGS 1


typedef int DataType;

typedef struct SListNode
{
	struct SListNode* _next;
	DataType _data;
}SListNode;


SListNode* BuySListNode(DataType x);
void SListPrint(SListNode* pHead);
void SListDestory(SListNode** ppHead);

void SListPushBack(SListNode** ppHead, DataType x);
void SListPopBack(SListNode** ppHead);
void SListPushFront(SListNode** ppHead, DataType x);
SListNode* SListFind(SListNode* pHead, DataType x);
void SListInsest(SListNode** ppHead, SListNode* pos, DataType x);
void SListErase(SListNode** ppHead, SListNode* pos);