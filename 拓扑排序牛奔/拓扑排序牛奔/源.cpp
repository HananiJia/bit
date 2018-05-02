#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MaxVernum 20  //定义图最大顶点数目
#define STACK_INIT_SIZE 10                                      //存储空间初始分配量
#define STACKINCREMENT 2   //存储空间分配增量
int degree[MaxVernum];
typedef int SElemType;
typedef char VertexType;

//存储图的边
typedef struct ArcNode
{
	SElemType Ver;//存储边所指向的顶点
	//SElemType Weight;//存储该边的权重
	struct ArcNode *next;//指向下一个边的指针结点
}ArcNode;

//存储图的顶点
typedef struct VerNode
{
	int data;//存储该顶点的数据
	struct ArcNode *firstArc;// 边的头指针
	SElemType indegree;//该结点的入度
	SElemType flag;//设定一个标志用于后期判断最短路径是一条还是多条
}VerNode, AdjList[MaxVernum];

//存储图
typedef struct
{
	AdjList adjlist;
	SElemType Arcnum;//存储图中的边的数目
	SElemType Vernum;//存储图中的顶点的数目
}ALGraph;


//栈的顺序存储结构表示
typedef struct SqStack
{
	SElemType *base;                        //栈底地址
	SElemType *top;                         //栈顶指针
	int stacksize;                          //当前已经分配的存储空间
}SqStack;

//构造一个空栈
int InitStack(SqStack &S)
{
	//为栈底分分配一个指定大小的存储空间
	(S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
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
int Push(SqStack *S, SElemType e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)
			exit(0);
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return 1;
}




//若栈不为空，则删除S栈顶元素用e返回其值，并返回1，否则返回0
int Pop(SqStack *S, SElemType &e)
{
	if ((*S).top == (*S).base)
	{
		return 0;
	}
	e = *--(*S).top;
	return 1;
}
void Finedegree(ALGraph *G)
{
	int j = 0;
	for (j = 0; j<G->Vernum; j++)
	{

		degree[j] = G->adjlist[j].indegree;
		//printf("第%d个顶点即%c入度为:%d\n", j + 1, G->adjlist[j].data, degree[j]);
	}
}
//有向图的G采用邻接表存储结构，若G无回路，则输出G的顶点的一个拓扑结构
int TopologicalSort(ALGraph *G)
{
	int i, k;
	int count = 0;
	SqStack S;
	ArcNode *p;
	int e = 0;
	int j = 0;
	p = NULL;
	InitStack(S);
	Finedegree(G);
	for (i = 0; i<G->Vernum; i++)
	{
		if (!degree[i])
			Push(&S, i);//把入度为零的节点压栈
	}
	printf("拓扑排列如下:\n");
	while (!StackEmpty(S))//只要栈不是空的就一直进行
	{
		Pop(&S, i);//栈不是空的那就将里边的一个出栈然后输出
		printf("%d", G->adjlist[i].data);
		count++;
		for (p = G->adjlist[i].firstArc; p; p = p->next)
		{
			k = p->Ver;
			if (!(--degree[k]))
				Push(&S, k);


		}
	}
	if (count < G->Vernum)
	{

		printf("您所创建的图存在环不可以拓扑排序");
		return 0;
	}
	printf("\n");
	return 0;
}


int IfArc(ALGraph *G,int a)//检查用户再次输入顶点是否在图中
{
	int i = 0;
	for (i = 0; i < G->Vernum; i++)
	{
		if (a==G->adjlist[i].data)
			return i;//如果输入的顶点和图中某一顶点数值相同返回该顶点在图中的位置，return i之后就不会再执行函数之后的内容
	}
	return -1;//如果for循环结束之后还没有找到对应的值那么函数返回值为-1

}
//构造函数 创建图
void CreateALGraph(ALGraph *G)
{
	int  v1;
	int v2;
	int i = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	ArcNode *p;
	printf("请输入你想组建图的顶点总数和弧边总数:\n");
	scanf("%d %d", &G->Vernum, &G->Arcnum);
	for (i = 0; i < G->Vernum; i++)//初始化图中的顶点信息
	{
		fflush(stdin);//清空缓存区以免将上一步的空格回车等信息输入
		printf("请输入第%d个顶点", i + 1);
		scanf("%s", &G->adjlist[i].data);//给所有顶点数据进行初始化
		G->adjlist[i].firstArc = NULL;//将每个顶点的头指针，以及入度初始化
		G->adjlist[i].flag = 0;
		G->adjlist[i].indegree = 0;

	}
	system("cls");
	
	for (i = 0; i < G->Arcnum; i++)//初始化图中的弧边信息
	{

		printf("请输入前顶点\n");
		scanf("%d ", &v1);
		printf("请输入后顶点\n");
		scanf("%d ", &v2);
		printf("hahaha");
		m = IfArc(G, v1);
		n = IfArc(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));//对p进行空间分配分配的大小是一个ArcNode结构体的大小
		p->Ver = n;//顶点信息
		p->next = G->adjlist[m].firstArc;//将刚刚输入的两个顶点链接起来
		G->adjlist[m].firstArc = p;
		G->adjlist[n].indegree++;
	}
	system("cls");

}

//求关键路径、关键活动函数

void menu()
{
	printf("************************************\n");
	printf("********请选择您要实现的功能********\n");
	printf("*************1.拓扑排序*************\n");
	printf("*************2.关键路径*************\n");
	printf("*************0.退出系统*************\n");
	printf("************************************\n");
	printf("******请按对应数字按钮以回车结束****\n");
}
int  main()
{
	int set = 0;
	ALGraph G;
	menu();
	scanf("%d", &set);
	while (set)
	{
		switch (set)
		{

		case 1:
			CreateALGraph(&G);
			TopologicalSort(&G);
			break;

		case 2:
			CreateALGraph(&G);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
		menu();
		scanf("%d", &set);
	}

	system("pause");
	return 0;
            }
