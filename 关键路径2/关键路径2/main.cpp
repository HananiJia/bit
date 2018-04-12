#define _CRT_SECURE_NO_WARNINGS 1 

#include <stdio.h>    
#include <stdlib.h>    
#include<string.h>
#define MaxVerNum 20    

int visited[MaxVerNum];

typedef char VertexType;

typedef struct ArcNode
{
	int adjvex;                                         //该弧指向的顶点位置    
	struct ArcNode * nextarc;          //指向下一个表结点    
	int info;                                      //权值信息    
}ArcNode;                                              //边结点类型    

typedef struct VNode
{
	VertexType data;
	int indegree;
	ArcNode * firstarc;
}VNode, Adjlist[MaxVerNum];


typedef struct
{
	Adjlist vertices;            //邻接表    
	int vernum; //用于记录有向图中的顶点数目
	int arcnum; //用于记录有向图中所有弧的数目   
}ALGraph;//有向图的存储结构

//查找符合的数据在数组中的下标    
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

//常见图的邻接矩阵    
void CreateALGraph(ALGraph &G)
{
	int i, j, k, w;
	char v1, v2;
	ArcNode * p;
	printf("输入顶点数和弧数: ");
	scanf("%d %d", &G.vernum, &G.arcnum);//从键盘输入有向图顶点数目和弧的数目
	printf("请输入顶点!\n");
	for (i = 0; i < G.vernum; i++)
	{
		printf("请输入第 %d 个顶点: \n", i+1);
		fflush(stdin);//清空输入缓存区，以防止刚刚输入顶点数目之后的回车键被读取
		scanf("%c", &G.vertices[i].data);
		G.vertices[i].firstarc = NULL;//对输入的顶点指针域进行初始化
		G.vertices[i].indegree = 0;
	}

	for (k = 0; k < G.arcnum; k++)
	{
		printf("请输入弧的顶点和相应权值(v1, v2, w): \n");
		//清空输入缓冲区    
		fflush(stdin);
		scanf("%c %c %d", &v1, &v2, &w);
		i = LocateVer(G, v1);
		j = LocateVer(G, v2);
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
		G.vertices[j].indegree++;                   //vi->vj, vj入度加1    
	}
	return;
}

//求图的关键路径函数    
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
				Ve[k] = Ve[i] + p->info;//求某事件的最早发生时间即所有路径中的最长时间
			p = p->nextarc;
		}
	}

	for (i = 0; i < G.vernum; i++)
		Vl[i] = Ve[G.vernum - 1];
	for (i = G.vernum - 2; i >= 0; i--)        //从后往前推，求某事件发生的最短时间    
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
			e = Ve[i];              //最早开始时间为时间vi的最早发生时间    
			l = Vl[k] - p->info;             //最迟开始时间    
			 //关键活动    
			printf("(%c, %c), e = %2d, l = %2d", G.vertices[i].data, G.vertices[k].data, e, l);
			if (e ==l)
				printf(" 关键路径 ");
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
	printf("以下是查找图的关键路径的程序。\n");
	CreateALGraph(G);
	CriticalPath(G);
	system("pause");
}