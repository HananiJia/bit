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
}VNode, AdjList[MaxSize];
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;
}AdjGraph;

AdjGraph AG，ag;

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

//Kruskal
void kruskal(Graph * graph, Graph * kruskal_tree)
{
	int visited[graph->vertexs];
	int i, j;
	Edge edge[graph->brim];
	int v1, v2, vs1, vs2;
	Arc_node * cur, *tmp;

	for (i = 0; i < graph->vertexs; i++)
		visited[i] = i;

	for (i = 0, j = 0; i < graph->vertexs; i++)
	{
		cur = graph->adjlist[i].next;
		while (cur != NULL)
		{
			if (cur->pos > i)
			{
				edge[j].head = i;
				edge[j].tail = cur->pos;
				edge[j].power = cur->distance;
				j++;
			}
			cur = cur->next;
		}
	}

	init_kruskal(graph, kruskal_tree);
	my_sort(edge, graph->brim);

	for (i = 0; i < graph->brim; i += 1)
	{
		v1 = edge[i].head;
		v2 = edge[i].tail;
		vs1 = visited[v1];
		vs2 = visited[v2];
		if (vs1 != vs2)
		{
			if (kruskal_tree->adjlist[v1].next == NULL)
			{
				kruskal_tree->adjlist[v1].next = make_node(v2, edge[i].power);
			}
			else
			{
				tmp = kruskal_tree->adjlist[v1].next;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = make_node(v2, edge[i].power);
			}
			for (j = 0; j < graph->vertexs; j++)
			{
				if (visited[j] == vs2)
					visited[j] = vs1;
			}
		}
	}
}

int main() {
	CreateGraph(AG);
	kruskal(&ag, &AG);
	return 0;
}

