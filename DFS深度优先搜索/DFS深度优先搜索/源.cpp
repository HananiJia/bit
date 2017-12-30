#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
/*ͼ���ڽӱ����Ͷ���*/
typedef char VertexType[4];
typedef char InfoPtr;
typedef int VRType;
#define MaxSize 50        /*��󶨵����*/
typedef enum{ DG, DN, UG, UN }GraphKind;        /*ͼ�����ͣ�����ͼ��������������ͼ��������*/

typedef struct ArcNode            /*�߽ڵ�Ķ���*/
{
	int adjvex;           /*��ָ��Ķ���λ��*/
	InfoPtr *info;        /*�뻡��ص���Ϣ*/
	struct ArcNode *nextarc;     /*ָʾ��һ����ö������ڽӵĶ���*/
}ArcNode;

typedef struct VNode         /*ͷ������Ͷ���*/
{
	VertexType data;         /*���ڴ��涥��*/
	ArcNode *firstarc;         /*ָʾ��һ����ýڵ��ڽӵĶ���*/
}VNode, AdjList[MaxSize];

typedef struct            /*ͼ�����Ͷ���*/
{
	AdjList vertex;
	int vexnum, arcnum;    /*ͼ�Ķ�����Ŀ�뻡����Ŀ*/
	GraphKind kind;       /*ͼ������*/
}AdjGraph;
/*��������*/
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
	VertexType v1, v2;/*������������v1��v2*/
	ArcNode *p;
	printf("������ͼ�Ķ�����������(���ŷָ�):");
	scanf("%d,%d", &(*G).vexnum, &(*G).arcnum);
	printf("������%d�������ֵ:\n", G->vexnum);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%s", G->vertex[i].data);
		G->vertex[i].firstarc = NULL;
	}
	printf("�����뻡β�ͻ�ͷ(�Կո���Ϊ���):\n");
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%s %s", v1, v2);
		i = LocateVertex(*G, v1);
		j = LocateVertex(*G, v2);
		/*��jΪ���iΪ���ߴ����ڽӱ�*/
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = NULL;
		p->nextarc = G->vertex[i].firstarc;
		G->vertex[i].firstarc = p;
		/*��iΪ���jΪ���ߴ����ڽӱ�*/
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = NULL;
		p->nextarc = G->vertex[j].firstarc;
		G->vertex[j].firstarc = p;
	}
	(*G).kind = UG;
}

int LocateVertex(AdjGraph G, VertexType v)    /*����ͼ�ж����Ӧλ��*/
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	if (strcmp(G.vertex[i].data, v) == 0)
		return i;
	return -1;
}

void DestroyGraph(AdjGraph *G)      /*��������ͼG*/
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

void DisplayGraph(AdjGraph G)     /*ͼ���ڽӱ�洢�ṹ�����*/
{
	int i;
	ArcNode *p;
	printf("%d������:\n", G.vexnum);
	for (i = 0; i<G.vexnum; i++)
		printf("%s ", G.vertex[i].data);
	printf("\n%d����\n", 2 * G.arcnum);
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertex[i].firstarc;
		while (p)
		{
			printf("%s��%s ", G.vertex[i].data, G.vertex[p->adjvex].data);
			p = p->nextarc;
		}
		printf("\n");
	}
}

int visited[MaxSize];          /*���ʱ�־����*/

void DFSTraverse(AdjGraph G)
{
	int v;
	for (v = 0; v < G.vexnum; v++)
		visited[v] = 0;      /*���ʱ�־�����ʼ��δ������*/
	for (v = 0; v < G.vexnum; v++)
	if (!visited[v])
		DFS(G, v);       /*��δ�����ʵĶ���v����������ȱ���*/
	printf("\n");
}

void DFS(AdjGraph G, int v)    /*�Ӷ���v�����ݹ���ȱ���ͼG*/
{
	int w;
	visited[v] = 1;     /*���ʱ������Ϊ�ѷ���*/
	Visit(G.vertex[v].data);    /*���ʵ�v������*/
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
	printf("�����ڽӱ�������ͼG��\n");
	CreateGraph(&G);
	printf("�������ͼG��\n");
	DisplayGraph(G);
	printf("ͼ����ȱ�����");
	DFSTraverse(G);
	printf("\n");
	DFSTraverse2(G, 0);
	printf("\n");
	DestroyGraph(&G);
	system("pause");
}