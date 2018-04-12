#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>    
#include <stdlib.h>    
#include<string.h>
#define MaxVerNum 20    

int visited[MaxVerNum];

typedef char VertexType;

typedef struct ArcNode
{
	int adjvex;                                         //�û�ָ��Ķ���λ��    
	struct ArcNode * nextarc;          //ָ����һ������    
	int info;                                      //Ȩֵ��Ϣ    
}ArcNode;                                              //�߽������    

typedef struct VNode
{
	VertexType data;
	int indegree;
	ArcNode * firstarc;
}VNode, Adjlist[MaxVerNum];


typedef struct
{
	Adjlist vertices;            //�ڽӱ�    
	int vernum; //���ڼ�¼����ͼ�еĶ�����Ŀ
	int arcnum; //���ڼ�¼����ͼ�����л�����Ŀ   
}ALGraph;//����ͼ�Ĵ洢�ṹ

//���ҷ��ϵ������������е��±�    
int LocateVer(ALGraph G, char u)
{
	int i;
	for (i = 0; i < G.vernum; i++)
	{
		if (u == G.vertices[i].data)
			return i;
	}
	if (i == G.vernum)
	{
		printf("Error u!\n");
		exit(1);
	}
	return 0;
}

//����ͼ���ڽӾ���    
void CreateALGraph(ALGraph &G)
{
	int i, j, k, w;
	char v1, v2;
	ArcNode * p;
	printf("���붥�����ͻ���: ");
	scanf("%d %d", &G.vernum, &G.arcnum);//�Ӽ�����������ͼ������Ŀ�ͻ�����Ŀ
	printf("�����붥��!\n");
	for (i = 0; i < G.vernum; i++)
	{
		printf("������� %d ������: \n", i+1);
		fflush(stdin);//������뻺�������Է�ֹ�ո����붥����Ŀ֮��Ļس�������ȡ
		scanf("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;//������Ķ���ָ������г�ʼ��
		G.vertices[i].indegree = 0;
	}

	for (k = 0; k < G.arcnum; k++)
	{
		printf("�����뻡�Ķ������ӦȨֵ(v1, v2, w): \n");
		//������뻺����    
		fflush(stdin);
		scanf("%c %c %d", &v1, &v2, &w);
		i = LocateVer(G, v1);
		j = LocateVer(G, v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		G.vertices[j].indegree++;                   //vi->vj, vj��ȼ�1    
	}
	return;
}

//��ͼ�Ĺؼ�·������    
void CriticalPath(ALGraph G)
{
	int i, k, e, l;
	int * Ve, *Vl;
	ArcNode * p;
	Ve = new int[G.vernum];
	Vl = new int[G.vernum];

	memset(Ve, 0, G.vernum);
	memset(Vl, 0, G.vernum);
	for (i = 0; i < G.vernum; i++)
	{
		ArcNode * p = G.vertices[i].firstarc;
		while (p)
		{
			k = p->adjvex;
			if (Ve[i] + p->info > Ve[k])
				Ve[k] = Ve[i] + p->info;//��ĳ�¼������緢��ʱ�伴����·���е��ʱ��
			p = p->nextarc;
		}
	}

	for (i = 0; i < G.vernum; i++)
		Vl[i] = Ve[G.vernum - 1];
	for (i = G.vernum - 2; i >= 0; i--)        //�Ӻ���ǰ�ƣ���ĳ�¼����������ʱ��    
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			k = p->adjvex;
			if (Vl[k] - p->info < Vl[i])
				Vl[i] = Vl[k] - p->info;
			p = p->nextarc;
		}
	}
 
	for (i = 0; i < G.vernum; i++)
	{
		p = G.vertices[i].firstarc;
		while (p)
		{
			k = p->adjvex;
			e = Ve[i];              //���翪ʼʱ��Ϊʱ��vi�����緢��ʱ��    
			l = Vl[k] - p->info;             //��ٿ�ʼʱ��    
			 //�ؼ��    
			printf("(%c, %c), e = %2d, l = %2d", G.vertices[i].data, G.vertices[k].data, e, l);
			if (e ==l)
				printf(" �ؼ�·�� ");
			printf("\n");
			p = p->nextarc;
		}
	}
	delete[] Ve;
	delete[] Vl;
}

void main()
{
	ALGraph G;
	printf("�����ǲ���ͼ�Ĺؼ�·���ĳ���\n");
	CreateALGraph(G);
	CriticalPath(G);
	system("pause");
}