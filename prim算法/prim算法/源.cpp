#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INTINITY INT_MAX                  //���ε����ֵ
#define MAX_VERTEX_NUM 20                 //��󶥵���

typedef struct ArcCell {
	int adj;
	int *info;                            //�뻡�йص���Ϣ
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	char vexs[MAX_VERTEX_NUM];            //���ڴ洢����
	AdjMatrix arc;                        //�ڽӾ��󣬴洢�߻򻡵���Ϣ
	int vexnum, arcnum;                   //���������߱ߵ���Ŀ
}MGraph;

MGraph MG;

void CreateGraph(MGraph &MG) {
	int i, j, k, w, INfoFlag, len;
	char s[MAX_VERTEX_NUM];
	ArcCell v1, v2;
	printf("����������ͼ�Ķ������������� ������Ϣ��1/0����");
	scanf("%d, %d, %d", &MG.vexnum, &MG.arcnum, &INfoFlag);
	printf("������%d�������ֵ��С��%d���ַ�����\n", MG.vexnum, MG.vexnum);
	for (i = 0; i < MG.vexnum; i++)            //�������ĸ���������Ϣ
		scanf("%c", &MG.vexs[i]);
	for (i = 0; i < MG.vexnum; i++)            //��ʼ���ڽӾ���
	for (j = 0; j <MG.vexnum; j++) {
		MG.arc[i][j].adj = INTINITY;
		MG.arc[i][j].info = NULL;
	}
	printf("������%d�����Ļ�β����ͷ��Ȩֵ���ö��Ÿ�������\n", MG.arcnum);
	for (k = 0; k < MG.arcnum; k++) {             //�����ڽӾ���
		scanf("%c,%c,%d", &v1, &v2, &w);        //����һ���������Ķ��㼰Ȩֵ
		i = LocateVex(MG, v1);                   //ȷ��v1��v2��MG�е�λ��
		j = LocateVex(MG, v2);
		MG.arc[i][j].adj = w;                    //��<v1, v2>��Ȩֵ
		if (INfoFlag) {
			printf("�����뻡����Ϣ��");
			gets(s);
			len = strlen(s);
			if (len) {
				MG.arc[i][j].info = (char *)malloc((len + 1)*sizeof(char));
				strcpy(MG.arc[i][j].info, s);
			}
		}
	}
}

int LocateVex(MGraph M, char v) {                    //�ڶ��������в��Ҷ���v���ҵ������������е���ţ����򷵻�-1
	int i;
	for (i = 0; i < M.vexnum; i++)
	if (strcmp(M.vexs[i], v) == 0)
		return i;
	return -1;
}

void PrintGraph(MGraph MG) {
	int i, j;
	printf("����������%d������%d������ ���������ǣ�", MG.vexnum, MG.arcnum);
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
	printf("��С�������ĸ���Ϊ��\n");
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