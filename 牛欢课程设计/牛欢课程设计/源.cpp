#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 9
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 2
#define OK
#define ERROR



// 边表结点声明  
typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

// 顶点表结点声明  
typedef struct VertexNode
{
	int in;         // 顶点入度  
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
	int *base;                        //栈底地址
	int  *top;                         //栈顶指针
	int stacksize;                          //当前已经分配的存储空间
}SqStack;

int *etv, *ltv;

//构造一个空栈
int InitStack(SqStack &S)
{
	//为栈底分分配一个指定大小的存储空间
	(S).base = (int *)malloc(STACK_INIT_SIZE*sizeof(int));
	if (!(S).base)
		exit(0);
	(S).top = (S).base;                   //栈底与栈顶指针相同
	(S).stacksize = STACK_INIT_SIZE;
	return 1;
}



//若栈S为空栈（栈底指针和栈顶指针相同）, 则返回1，否则返回0
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}


//插入元素e为新的栈顶元素
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




//若栈不为空，则删除S栈顶元素用e返回其值，并返回1，否则返回0
int Pop(SqStack *S, int &e)
{
	if ((*S).top == (*S).base)
	{
		return 0;
	}
	e = *--(*S).top;
	return 1;
}


void CreatGraph(VertexNode *GL, int numVertexes, int numEdges)     //创建AOE网
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
	printf("请输入各个活动的信息<vi,vj,weight>\n");
	for (int j = 0; j < numEdges; j++)
		scanf_s("%d,%d,%d", &begin, &end, &weight);
	p = (EdgeNode*)malloc(sizeof(EdgeNode));
	p->adjvex = end - 1;
	p->weight = weight;
	GL[end - 1].in++;   //计算各顶点入度信息
	p->next = GL[begin - 1].firstedge;
}

// 拓扑排序算法  
// 若GL无回路，则输出拓扑排序序列并返回OK，否则返回ERROR  
void TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;        // 用于栈指针下标索引  
	int count = 0;      // 用于统计输出顶点的个数  
	int *stack;         // 用于存储入度为0的顶点  

	stack = (int *)malloc(GL->numVertexes * sizeof(int));

	for (i = 0; i < GL->numVertexes; i++)
	{
		if (0 == GL->adjList[i].in)
		{
			stack[++top] = i;   // 将度为0的顶点下标入栈  
		}
	}

	// 初始化etv都为0  
	top2 = 0;
	etv = (int *)malloc(GL->numVertexes*sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		etv[i] = 0;
	}
	stack2 = (int *)malloc(GL->numVertexes*sizeof(int));

	while (0 != top)
	{
		gettop = stack[top--];      // 出栈  
		// printf("%d -> ", GL->adjList[gettop].data);   
		stack2[++top2] = gettop;    // 保存拓扑序列顺序 C1 C2 C3 C4 .... C9  
		count++;

		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			// 注意：下边这个if条件是分析整个程序的要点！  
			// 将k号顶点邻接点的入度-1，因为他的前驱已经消除  
			// 接着判断-1后入度是否为0，如果为0则也入栈  
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

	if (count < GL->numVertexes) // 如果count小于顶点数，说明存在环  
	{
		return ERROR;
	}
	else
	{
		return OK;
	}
}

// 求关键路径，GL为有向图，输出GL的各项关键活动  
void CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, gettop, k, j;
	int ete, lte;

	// 调用改进后的拓扑排序，求出etv和stack2的值  
	TopologicalSort(GL);

	// 初始化ltv都为汇点的时间  
	ltv = (int *)malloc(GL->numVertexes*sizeof(int));
	for (i = 0; i < GL->numVertexes; i++)
	{
		ltv[i] = etv[GL->numVertexes - 1];
	}

	// 从汇点倒过来逐个计算ltv  
	while (0 != top2)
	{
		gettop = stack2[top2--];    // 注意，第一个出栈是汇点  
		for (e = GL->adjList[gettop].firstedge; e; e = e->next)
		{
			k = e->adjvex;
			if ((ltv[k] - e->weight) < ltv[gettop])
			{
				ltv[gettop] = ltv[k] - e->weight;
			}
		}
	}

	// 通过etv和ltv求ete和lte  
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
