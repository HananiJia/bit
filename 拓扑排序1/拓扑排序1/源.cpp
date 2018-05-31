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
graph *Creat() //����ͼ
{
	int  i, j, k, w;
	graph *G = (graph*)malloc(sizeof(graph));
	printf("�����붥�����ͱ������ÿո��������5  8\n");
	scanf("%d%d", &G->vCant, &G->arcnum);
	for (i = 0; i<G->vCant; ++i)
	for (j = 0; j<G->vCant; ++j)  G->adjMatrix[i][j] = 0;
	printf("��������������������㼰��Ȩ�ÿո������3 5\n");
	for (k = 0; k<G->arcnum; ++k) {
		printf("��%d����: ", k + 1);
		getchar();
		scanf("%d%d%d", &i, &j, &w);
		G->adjMatrix[i - 1][j - 1] = w;
	}
	return G;
}
void topSort(graph *g, int *sort)//��������
{
	int *isSorted, *inDegree, i, j, sorted = 0, t = 0;
	isSorted = (int*)malloc(sizeof(int)*g->vCant);//��¼�����Ƿ��Ѿ�ɾ��
	inDegree = (int*)malloc(sizeof(int)*g->vCant);//��¼��������
	for (i = 0; i < g->vCant; i++)//��ʼ��ʱ���㶼��ͼ����isSortedΪ
		isSorted[i] = 0;
	for (j = 0; j < g->vCant; j++)//��������D��������
	{
		inDegree[j] = 0;
		for (i = 0; i < g->vCant; i++)
		{
			if (g->adjMatrix[i][j] != 0)
				inDegree[j]++;
		}
	}
	while (sorted < g->vCant)//��������ÿ����һ������
	{
		for (i = 0; i < g->vCant; i++)
		if (isSorted[i] == 0 && inDegree[i] == 0)
			break;
		if (i >= g->vCant)//�ж���Ч
		{
			printf("There is a cycle\n");
			break;
		}
		sort[t] = i;
		t++;
		printf("%d", i);//��Dbug  
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
/*void output(graph *G)//���ͼ
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
void keypath(graph *g)//�ؼ�·��
{
	int i = 0, j, k, m;
	int *ve, *vl, *e, *t, *w, *sort;
	ve = (int *)malloc(sizeof(int)*g->vCant);
	vl = (int *)malloc(sizeof(int)*g->vCant);
	sort = (int *)malloc(sizeof(int)*g->vCant);
	e = (int *)malloc(sizeof(int)*g->arcnum);
	t = (int *)malloc(sizeof(int)*g->arcnum);
	w = (int *)malloc(sizeof(int)*g->arcnum);
	topSort(g, sort);//��������
	ve[sort[i]] = 0;
	for (i = 0; i < g->vCant; i++)
	{
		ve[i] = 0;
		vl[i] = 0;
	}
	for (i = 1; i < g->vCant; i++)//�¼����緢����ʱ��
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
	for (i = g->vCant - 2; i >= 0; i--)//�¼���ٷ���ʱ��
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
	printf("�ؼ����·���ǣ�\n");
	for (i = 0; i < g->vCant;)//��ؼ�·��
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
	for (i = 0; i < g->vCant;)//��ؼ�·��
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
	printf("��ɸù���������Ҫ��������%d", o);
}
int main()
{
	graph *G;
	G = Creat();
	//output(G);
	keypath(G);
	return 0;
}