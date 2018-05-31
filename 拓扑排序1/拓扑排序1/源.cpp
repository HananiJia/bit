#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<malloc.h>
#define N 20
typedef struct graph
{
	int vCant;
	int arcnum;
	int type;
	int adjMatrix[N][N];
}graph;
graph *Creat() //创建图
{
	int  i, j, k, w;
	graph *G = (graph*)malloc(sizeof(graph));
	printf("请输入顶点数和边数（用空格隔开）如5  8\n");
	scanf("%d%d", &G->vCant, &G->arcnum);
	for (i = 0; i<G->vCant; ++i)
	for (j = 0; j<G->vCant; ++j)  G->adjMatrix[i][j] = 0;
	printf("输入各边依附的两个顶点及其权用空格隔开如3 5\n");
	for (k = 0; k<G->arcnum; ++k) {
		printf("第%d条边: ", k + 1);
		getchar();
		scanf("%d%d%d", &i, &j, &w);
		G->adjMatrix[i - 1][j - 1] = w;
	}
	return G;
}
void topSort(graph *g, int *sort)//拓扑排序
{
	int *isSorted, *inDegree, i, j, sorted = 0, t = 0;
	isSorted = (int*)malloc(sizeof(int)*g->vCant);//记录顶点是否已经删除
	inDegree = (int*)malloc(sizeof(int)*g->vCant);//记录顶点的入度
	for (i = 0; i < g->vCant; i++)//初始化时顶点都在图中设isSorted为
		isSorted[i] = 0;
	for (j = 0; j < g->vCant; j++)//计算所有D顶点的入度
	{
		inDegree[j] = 0;
		for (i = 0; i < g->vCant; i++)
		{
			if (g->adjMatrix[i][j] != 0)
				inDegree[j]++;
		}
	}
	while (sorted < g->vCant)//拓扑排序每次排一个过程
	{
		for (i = 0; i < g->vCant; i++)
		if (isSorted[i] == 0 && inDegree[i] == 0)
			break;
		if (i >= g->vCant)//判断无效
		{
			printf("There is a cycle\n");
			break;
		}
		sort[t] = i;
		t++;
		printf("%d", i);//有Dbug  
		isSorted[i] = 1;
		sorted++;
		for (j = 0; j < g->vCant; j++)
		{
			if (g->adjMatrix[i][j] != 0)
				inDegree[j]--;
		}
		//printf("\n");
	}
}
/*void output(graph *G)//输出图
{
for (int i = 0; i < G->vCant; i++)
{
for (int j = 0; j < G->vCant; j++)
{
printf("%d", G->adjMatrix[i][j]);
}
printf("\n");
}
}*/
void keypath(graph *g)//关键路径
{
	int i = 0, j, k, m;
	int *ve, *vl, *e, *t, *w, *sort;
	ve = (int *)malloc(sizeof(int)*g->vCant);
	vl = (int *)malloc(sizeof(int)*g->vCant);
	sort = (int *)malloc(sizeof(int)*g->vCant);
	e = (int *)malloc(sizeof(int)*g->arcnum);
	t = (int *)malloc(sizeof(int)*g->arcnum);
	w = (int *)malloc(sizeof(int)*g->arcnum);
	topSort(g, sort);//拓扑排序
	ve[sort[i]] = 0;
	for (i = 0; i < g->vCant; i++)
	{
		ve[i] = 0;
		vl[i] = 0;
	}
	for (i = 1; i < g->vCant; i++)//事件最早发生的时间
	{
		k = sort[i];
		for (j = 0; j < g->vCant; j++)
		{
			if (g->adjMatrix[j][k] > 0)
			{
				if (ve[j] + g->adjMatrix[j][k] > ve[k])
					ve[k] = ve[j] + g->adjMatrix[j][k];
			}
		}
	}
	vl[sort[g->vCant - 1]] = ve[sort[g->vCant - 1]];
	for (i = g->vCant - 2; i >= 0; i--)//事件最迟发生时间
	{
		k = sort[i];
		m = 0;
		for (j = 0; j < g->vCant; j++)
		{
			if (g->adjMatrix[k][j] > 0)
			{
				if (m == 0)
				{
					vl[k] = vl[j] - g->adjMatrix[k][j];
					m = 1;
				}
				if (m == 1)
				{
					if (vl[j] - g->adjMatrix[k][j] < vl[k])
						vl[k] = vl[j] - g->adjMatrix[k][j];
				}
			}
		}
	}
	int o = 0;
	k = -1;
	printf("关键活动和路径是：\n");
	for (i = 0; i < g->vCant;)//求关键路径
	{
		for (j = 0; j < g->vCant; j++)
		{
			k++;
			if (g->adjMatrix[i][j] > 0)
			{
				e[k] = ve[i];
				t[k] = vl[j];
				w[k] = g->adjMatrix[i][j];
				if (t[k] - e[k] == w[k])
				{
					printf("%d,<%d%d>", g->adjMatrix[i][j], i + 1, j + 1);
					m = j;
				}
				o = o + w[k];
				if (t[k] - e[k] == w[k])break;
			}

		}
		i = m;
		if (m == 8)break;
	}
	k = -1;
	printf("\n");
	for (i = 0; i < g->vCant;)//求关键路径
	{
		for (j = g->vCant - 1; j >= 0; j--)
		{
			k++;
			if (g->adjMatrix[i][j] > 0)
			{
				e[k] = ve[i];
				t[k] = vl[j];
				w[k] = g->adjMatrix[i][j];
				if (t[k] - e[k] == w[k])
				{
					printf("%d,<%d%d>", g->adjMatrix[i][j], i + 1, j + 1);
					m = j;
				}
				if (t[k] - e[k] == w[k])break;
			}

		}
		i = m;
		if (m == 8)break;
	}
	printf("完成该工程最少需要的天数是%d", o);
}
int main()
{
	graph *G;
	G = Creat();
	//output(G);
	keypath(G);
	return 0;
}