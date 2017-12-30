#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
/*图的邻接表类型定义*/
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MaxSize 50        /*最大定点个数*/
typedef enum{ DG, DN, UG, UN }GraphKind;        /*图的类型：有向图，有向网，无向图，无向网*/

typedef struct ArcNode            /*边节点的定义*/
{
	int adjvex;           /*弧指向的顶点位置*/
	InfoPtr *info;        /*与弧相关的信息*/
	struct ArcNode *nextarc;     /*指示下一个与该顶点相邻接的顶点*/
}ArcNode;

typedef struct VNode         /*头结点类型定义*/
{
	VertexType data;         /*用于储存顶点*/
	ArcNode *firstarc;         /*指示第一个与该节点邻接的顶点*/
}VNode, AdjList[MaxSize];

typedef struct            /*图的类型定义*/
{
	AdjList vertex;
	int vexnum, arcnum;    /*图的顶点数目与弧的数目*/
	GraphKind kind;       /*图的类型*/
}AdjGraph;
/*函数声明*/
int LocateVertex(AdjGraph G, VertexType v);
void CreateGraph(AdjGraph *G);
void DisplayGraph(AdjGraph G);
void DestroyGraph(AdjGraph *G);
void DFSTraverse(AdjGraph G);
void DFS(AdjGraph G, int v);
int FirstAdjVertex(AdjGraph G, VertexType v);
int NextAdjVertex(AdjGraph G, VertexType v, VertexType w);
void Visit(VertexType v);

void CreateGraph(AdjGraph *G)
{
	int i, j, k;
	VertexType v1, v2;/*定义两个顶点v1和v2*/
	ArcNode *p;
	printf("请输入图的顶点数，边数(逗号分隔):");
	scanf("%d,%d", &(*G).vexnum, &(*G).arcnum);
	printf("请输入%d个顶点的值:\n", G->vexnum);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%s", G->vertex[i].data);
		G->vertex[i].firstarc = NULL;
	}
	printf("请输入弧尾和弧头(以空格作为间隔):\n");
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%s %s", v1, v2);
		i = LocateVertex(*G, v1);
		j = LocateVertex(*G, v2);
		/*以j为入边i为出边创建邻接表*/
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = NULL;
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;
		/*以i为入边j为出边创建邻接表*/
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = NULL;
		p->nextarc = G->vertex[j].firstarc;
		G->vertex[j].firstarc = p;
	}
	(*G).kind = UG;
}

int LocateVertex(AdjGraph G, VertexType v)    /*返回图中顶点对应位置*/
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	if (strcmp(G.vertex[i].data, v) == 0)
		return i;
	return -1;
}

void DestroyGraph(AdjGraph *G)      /*销毁无向图G*/
{
	int i;
	ArcNode *p, *q;
	for (i = 0; i<(*G).vexnum; ++i)
	{
		p = G->vertex[i].firstarc;
		if (p != NULL)
		{
			q = p->nextarc;
			free(p);
			p = q;
		}
	}
	(*G).vexnum = 0;
	(*G).arcnum = 0;
}

void DisplayGraph(AdjGraph G)     /*图的邻接表存储结构的输出*/
{
	int i;
	ArcNode *p;
	printf("%d个顶点:\n", G.vexnum);
	for (i = 0; i<G.vexnum; i++)
		printf("%s ", G.vertex[i].data);
	printf("\n%d条边\n", 2 * G.arcnum);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertex[i].firstarc;
		while (p)
		{
			printf("%s→%s ", G.vertex[i].data, G.vertex[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int visited[MaxSize];          /*访问标志数组*/

void DFSTraverse(AdjGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;      /*访问标志数组初始化未被访问*/
	for (v = 0; v < G.vexnum; v++)
	if (!visited[v])
		DFS(G, v);       /*对未被访问的顶点v进行深度优先遍历*/
	printf("\n");
}

void DFS(AdjGraph G, int v)    /*从顶点v出发递归深度遍历图G*/
{
	int w;
	visited[v] = 1;     /*访问标记设置为已访问*/
	Visit(G.vertex[v].data);    /*访问第v个顶点*/
	for (w = FirstAdjVertex(G, G.vertex[v].data); w >= 0; w = NextAdjVertex(G, G.vertex[v].data, G.vertex[w].data))
	if (!visited[w])
		DFS(G, w);
}

int FirstAdjVertex(AdjGraph G, VertexType v)
{
	ArcNode *p;
	int v1;
	v1 = LocateVertex(G, v);
	p = G.vertex[v1].firstarc;
	if (p)
		return p->adjvex;
	else
		return -1;
}

int NextAdjVertex(AdjGraph G, VertexType v, VertexType w)
{
	ArcNode *p, *next;
	int v1, w1;
	v1 = LocateVertex(G, v);
	w1 = LocateVertex(G, w);
	for (next = G.vertex[v1].firstarc; next;)
	if (next->adjvex != w1)
		next = next->nextarc;
	p = next;
	if (!p || !p->nextarc)
		return -1;
	else
		return p->nextarc->adjvex;
}

void Visit(VertexType v)
{
	printf("%s ", v);
}

int DFSTraverse2(AdjGraph G, int v)
{
	int i, visited[MaxSize], top;
	ArcNode *stack[MaxSize], *p;
	for (i = 0; i < G.vexnum; i++)
		visited[i] = 0;
	top = -1;
	p = G.vertex[v].firstarc;
	while (top> -1 || p != NULL)
	{
		while (p != NULL)
		if (visited[p->adjvex] == 1)
			p = p->nextarc;
		else
		{
			Visit(G.vertex[p->adjvex].data);
			visited[p->adjvex] = 1;
			stack[++top] = p;
			p = G.vertex[p->adjvex].firstarc;
		}
		if (top > -1)
		{
			p = stack[top--];
			p = p->nextarc;
		}
	}
}

void main()
{
	AdjGraph G;
	printf("采用邻接表创建无向图G：\n");
	CreateGraph(&G);
	printf("输出无向图G：\n");
	DisplayGraph(G);
	printf("图的深度遍历：");
	DFSTraverse(G);
	printf("\n");
	DFSTraverse2(G, 0);
	printf("\n");
	DestroyGraph(&G);
	system("pause");
}