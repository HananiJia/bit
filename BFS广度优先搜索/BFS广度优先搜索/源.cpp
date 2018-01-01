#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 50
typedef struct ArcNode{
	int adjvex;
	char *info;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode {
	char date;
	ArcNode *firstarc;
}VNode, vertices[MaxSize];
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;
}AdjGraph;

AdjGraph AG;

int LocateVertex(AdjGraph G, char v);
void DisplayGraph(AdjGraph G);

void CreateGraph(AdjGraph G){
	int i, j, k;
	char v1, v2;/*定义两个顶点v1和v2*/
	ArcNode *p;
	printf("请输入顶点数，边数:");
	scanf("%d,%d", &G.vexnum, &G.arcnum);
	printf("请输入%d个顶点的值:\n", G.vexnum);
	for (i = 0; i < G.vexnum; i++)
	{
		scanf("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	printf("请输入弧尾，弧头:\n");
	for (k = 0; k < G.arcnum; k++)
	{
		scanf("%c,%c", &v1, &v2);
		i = LocateVertex(G, v1);
		j = LocateVertex(G, v2);

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = NULL;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;

		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->info = NULL;
		p->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p;
	}
}

int LocateVertex(AdjGraph G, char v) {
	int i;
	for (i = 0; i < G.vexnum; i++)
	if (strcmp(G.vertices[i].data, v) == 0)
		return i;
	return -1;
}

void DisplayGraph(AdjGraph G)     /*图的邻接表存储结构的输出*/
{
	int i;
	ArcNode *p;
	printf("顶点:\n");
	for (i = 0; i<G.vexnum; i++)
		printf("%c ", G.vertices[i].data);
	printf("边:\n");
	for (i = 0; i < G.vexnum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			printf("%c→%c ", G.vertices[i].data, G.vertices[p->adjvex].data);
			p = p->nextarc;
		}
	}
	printf("\n");
}

//BFS
int visited[MaxSize];
void BFSTraverse(AdjGraph AG) {
	int v, u, w, front, rear;
	ArcNode *p;
	int quene[MaxSize];
	front = rear = -1;
	for (v = 0; v < AG.vexnum; v++)
		visited[v] = 0;
	v = 0;
	visited[v] = 1;
	printf("%c ", AG.vertices[v].data);
	rear = (rear + 1) % MaxSize;
	quene[rear] = v;
	while (front < rear) {
		front = (front = 1) % MaxSize;
		v = quene[front];
		p = AG.vertices[v].firstarc;
		while (p != NULL) {
			if (visited[p->adjvex] == 0) {
				visited[p->adjvex] = 1;
				printf("%c ", AG.vertices[p->adjvex].date);
				rear = (rear + 1) % MaxSize;
				quene[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}

int main() {
	CreateGraph(AG);
	BFSTraverse(AG);
	return 0;
}