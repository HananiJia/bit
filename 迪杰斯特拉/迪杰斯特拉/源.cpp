#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 20
#define INFINITY 1000

typedef char VertexType;

typedef struct Graph {         //����ͼ���ڽӾ����ʾ���ṹ
	VertexType ver[MaxSize + 1];
	int edg[MaxSize][MaxSize];
}Graph;

void CreateGraph(Graph *g) {           //�ڽӾ���ͼ�����ɺ���
	int i = 0;
	int j = 0;
	int VertexNum;
	VertexType Ver;

	printf("������ͼ�Ķ���:\n");
	while ('\n' != (Ver = getchar()))
		g->ver[i++] = Ver;
	g->ver[i] = '\0';

	VertexNum = strlen(g->ver);
	printf("��������Ӧ�ĵ��ڽӾ���:\n");
	for (i = 0; i<VertexNum; i++)
	for (j = 0; j<VertexNum; j++)
		scanf("%d", &g->edg[i][j]);
}


void PrintGraph(Graph g) {        //���ͼ�Ľ���ʶ�����ڽӾ���
	int i, j;
	int VertexNum = strlen(g.ver);
	printf("ͼ�Ķ���Ϊ:\n");
	for (i = 0; i<VertexNum; i++)
		printf("%c ", g.ver[i]);
	printf("\n");

	printf("ͼ���ڽӾ���Ϊ:\n");
	for (i = 0; i<VertexNum; i++) {
		for (j = 0; j<VertexNum; j++)
			printf("%d ", g.edg[i][j]);
		printf("\n");
	}
}

int CalVerNum(Graph g) {       //��ͼ�Ķ�����
	return strlen(g.ver);
}


void SetWeight(Graph *g) {          //�����ڽӵĶ���֮���Ȩֵ����ΪINFINITY
	for (int i = 0; i<CalVerNum(*g); i++)
	for (int j = 0; j<CalVerNum(*g); j++)
	if (0 == g->edg[i][j])
		g->edg[i][j] = INFINITY;
}


void Dijkstra(Graph g) {        //DIJ�����·������
	int VertexNum = CalVerNum(g);
	int j;
	int mini;
	int index = 0;
	int *used = (int *)malloc(sizeof(int)*VertexNum);
	int *distance = (int *)malloc(sizeof(int)*VertexNum);
	int *parent = (int *)malloc(sizeof(int)*VertexNum);
	int *last = (int *)malloc(sizeof(int)*VertexNum);

	SetWeight(&g);

	for (int i = 0; i<VertexNum; i++) {
		used[i] = 0;
		distance[i] = g.edg[0][i];   //��ʼ��Ϊ����Ϊ0�Ķ���ľ���
		last[i] = 0;
	}

	used[0] = 1;
	parent[index++] = 0;

	for (i = 0; i<VertexNum - 1; i++) {
		j = 0;
		mini = INFINITY;

		for (int k = 0; k<VertexNum; k++)
		if ((0 == used[k]) && (distance[k] < mini)) {
			mini = distance[k];
			j = k;			//jΪ�ո��ҵ���V-U�е�Դ��·����̵Ķ���
		}

		used[j] = 1;

		for (k = 0; k<VertexNum; k++)
		if ((0 == used[k]) && (distance[k] > distance[j] + g.edg[j][k])) {   //�����ж����¼���U���ϣ��Ծ�������distance���и��£��Ƚ�ԭ·�����������¼���Ķ���Ϊ�м���·������
			distance[k] = distance[j] + g.edg[j][k];
		}

		parent[index++] = j;
	}

	printf("%c��%c�����·��������������Ϊ:\n", g.ver[0], g.ver[VertexNum - 1]);
	for (i = 0; i<index; i++)
		printf("%c ", g.ver[parent[i]]);
	printf("\n");

	printf("���·������Ϊ: %d\n", mini);

}

int main()
{
	Graph g;
	CreateGraph(&g);
	Dijkstra(g);
	return 0;
}