#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTINITY INT_MAX                  //整形的最大值
#define MAX_VERTEX_NUM 20                 //最大顶点数

typedef struct ArcCell {
	int adj;
	int *info;                            //与弧有关的信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	char vexs[MAX_VERTEX_NUM];            //用于存储顶点
	AdjMatrix arc;                        //邻接矩阵，存储边或弧的信息
	int vexnum, arcnum;                   //定点数或者边的数目
}MGraph;

MGraph MG;

void CreateGraph(MGraph &MG) {
	int i, j, k, w, INfoFlag, len;
	char s[MAX_VERTEX_NUM];
	ArcCell v1, v2;
	printf("请输入无向图的定点数，弧数， 弧的信息（1/0）：");
	scanf("%d, %d, %d", &MG.vexnum, &MG.arcnum, &INfoFlag);
	printf("请输入%d个顶点的值（小于%d个字符）：\n", MG.vexnum, MG.vexnum);
	for (i = 0; i < MG.vexnum; i++)            //保存网的各个顶点信息
		scanf("%c", &MG.vexs[i]);
	for (i = 0; i < MG.vexnum; i++)            //初始化邻接矩阵
	for (j = 0; j <MG.vexnum; j++) {
		MG.arc[i][j].adj = INTINITY;
		MG.arc[i][j].info = NULL;
	}
	printf("请输入%d条弧的弧尾，弧头，权值（用逗号隔开）：\n", MG.arcnum);
	for (k = 0; k < MG.arcnum; k++) {             //构造邻接矩阵
		scanf("%c,%c,%d", &v1, &v2, &w);        //输入一条边依附的顶点及权值
		i = LocateVex(MG, v1);                   //确定v1，v2在MG中的位置
		j = LocateVex(MG, v2);
		MG.arc[i][j].adj = w;                    //弧<v1, v2>的权值
		if (INfoFlag) {
			printf("请输入弧的信息：");
			gets(s);
			len = strlen(s);
			if (len) {
				MG.arc[i][j].info = (char *)malloc((len + 1)*sizeof(char));
				strcpy(MG.arc[i][j].info, s);
			}
		}
	}
}

int LocateVex(MGraph M, char v) {                    //在顶点向量中查找顶点v，找到返回在向量中的序号，否则返回-1
	int i;
	for (i = 0; i < M.vexnum; i++)
	if (strcmp(M.vexs[i], v) == 0)
		return i;
	return -1;
}

void PrintGraph(MGraph MG) {
	int i, j;
	printf("无向网具有%d个顶点%d条弧， 顶点依次是：", MG.vexnum, MG.arcnum);
	for (i = 0; i < MG.vexnum; i++)
		printf("%c ", MG.vexs[i]);
	for (i = 0; i < MG.vexnum; i++)
		printf("%8d", i);
	for (i = 0; i < MG.vexnum; i++)
	{
		printf("%d", i);
		for (j = 0; j < MG.vexnum; j++)
			printf("%8d", MG.arc[i][j].adj);
		printf("\n");
	}
}

//Prime
struct {
	char adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];

void MiniApanTree_PRIM(MGraph MG, char u) {
	int i, j, k;
	k = LocateVex(MG, u);
	for (j = 0; j < MG.vexnum; j++)
	if (j != k) {
		strcpy(closedge[j].adjvex, &u);
		closedge[j].lowcost = MG.arc[k][j].adj;
	}
	closedge[k].lowcost = 0;
	printf("最小生成树的各边为：\n");
	for (i = 1; i < MG.vexnum; i++) {
		k = mininum(closedge);
		printf("%c-%c\n", closedge[k].adjvex, MG.vexs[k]);
		closedge[k].lowcost = 0;
		for (j = 0; j < MG.vexnum; j++) {
			strcpy(closedge[j].adjvex, MG.vexs[k]);
			closedge[j].lowcost = MG.arc[k][j].adj;
		}
	}
}

int main() {
	CreateGraph(MG);
	MiniApanTree_PRIM(MG, u);
	return 0;
}