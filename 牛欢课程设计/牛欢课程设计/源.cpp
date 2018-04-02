#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 9
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 2
#define OK
#define ERROR



// �߱�������  
typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

// �����������  
typedef struct VertexNode
{
	int in;         // �������  
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

typedef struct SqStack
{
	int *base;                        //ջ�׵�ַ
	int  *top;                         //ջ��ָ��
	int stacksize;                          //��ǰ�Ѿ�����Ĵ洢�ռ�
}SqStack;

int *etv, *ltv;

//����һ����ջ
int InitStack(SqStack &S)
{
	//Ϊջ�׷ַ���һ��ָ����С�Ĵ洢�ռ�
	(S).base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!(S).base)
		exit(0);
	(S).top = (S).base;                   //ջ����ջ��ָ����ͬ
	(S).stacksize = STACK_INIT_SIZE;
	return 1;
}



//��ջSΪ��ջ��ջ��ָ���ջ��ָ����ͬ��, �򷵻�1�����򷵻�0
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}


//����Ԫ��eΪ�µ�ջ��Ԫ��
int Push(SqStack *S, int e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (int *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(int));
		if (!(*S).base)
			exit(0);
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return 1;
}




//��ջ��Ϊ�գ���ɾ��Sջ��Ԫ����e������ֵ��������1�����򷵻�0
int Pop(SqStack *S, int &e)
{
	if ((*S).top == (*S).base)
	{
		return 0;
	}
	e = *--(*S).top;
	return 1;
}


void CreatGraph(VertexNode *GL, int numVertexes, int numEdges)     //����AOE��
{
	int begin;
	int end;
	int weight;
	EdgeNode *p;
	for (int i = 0; i < numVertexes; i++)
	{
		GL[i].in = 0;
		GL[i].firstedge = NULL;
	}
	printf("��������������Ϣ<vi,vj,weight>\n");
	for (int j = 0; j < numEdges; j++)
		scanf_s("%d,%d,%d", &begin, &end, &weight);
	p = (EdgeNode*)malloc(sizeof(EdgeNode));
	p->adjvex = end - 1;
	p->weight = weight;
	GL[end - 1].in++;   //��������������Ϣ
	p->next = GL[begin - 1].firstedge;
}

// ���������㷨  
// ��GL�޻�·������������������в�����OK�����򷵻�ERROR  
void TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;        // ����ջָ���±�����  
	int count = 0;      // ����ͳ���������ĸ���  
	int *stack;         // ���ڴ洢���Ϊ0�Ķ���  

	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
		{
			stack[++top] = i;   // ����Ϊ0�Ķ����±���ջ  
		}
	}

	// ��ʼ��etv��Ϊ0  
	top2 = 0;
	etv = (int *)malloc(GL->numVertexes*sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		etv[i] = 0;
	}
	stack2 = (int *)malloc(GL->numVertexes*sizeof(int));

	while (0 != top)
	{
		gettop = stack[top--];      // ��ջ  
		// printf("%d -> ", GL->adjList[gettop].data);   
		stack2[++top2] = gettop;    // ������������˳�� C1 C2 C3 C4 .... C9  
		count++;

		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			// ע�⣺�±����if�����Ƿ������������Ҫ�㣡  
			// ��k�Ŷ����ڽӵ�����-1����Ϊ����ǰ���Ѿ�����  
			// �����ж�-1������Ƿ�Ϊ0�����Ϊ0��Ҳ��ջ  
			if (!(--GL->adjList[k].in))
			{
				stack[++top] = k;
			}

			if ((etv[gettop] + e->weight) > etv[k])
			{
				etv[k] = etv[gettop] + e->weight;
			}
		}
	}

	if (count < GL->numVertexes) // ���countС�ڶ�������˵�����ڻ�  
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}

// ��ؼ�·����GLΪ����ͼ�����GL�ĸ���ؼ��  
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;

	// ���øĽ���������������etv��stack2��ֵ  
	TopologicalSort(GL);

	// ��ʼ��ltv��Ϊ����ʱ��  
	ltv = (int *)malloc(GL->numVertexes*sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		ltv[i] = etv[GL->numVertexes - 1];
	}

	// �ӻ�㵹�����������ltv  
	while (0 != top2)
	{
		gettop = stack2[top2--];    // ע�⣬��һ����ջ�ǻ��  
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if ((ltv[k] - e->weight) < ltv[gettop])
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}

	// ͨ��etv��ltv��ete��lte  
	for (j = 0; j < GL->numVertexes; j++)
	{
		for (e = GL->adjList[j].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			ete = etv[j];
			lte = ltv[k] - e->weight;

			if (ete == lte)
			{
				printf("<v%d,v%d> length: %d , ", GL->adjList[j].data, GL->adjList[k].data, e->weight);
			}
		}
	}
}




int main()
{
	graphAdjList G;
	TopologicalSort(&G);
	CriticalPath(&G);
	return 0;
}
