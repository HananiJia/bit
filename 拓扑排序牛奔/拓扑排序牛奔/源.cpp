#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>



#define MaxVernum 20  //����ͼ��󶥵���Ŀ
#define STACK_INIT_SIZE 10                                      //�洢�ռ��ʼ������
#define STACKINCREMENT 2   //�洢�ռ��������
int degree[MaxVernum];
typedef int SElemType;
typedef char VertexType;

//�洢ͼ�ı�
typedef struct ArcNode
{
	SElemType Ver;//�洢����ָ��Ķ���
	//SElemType Weight;//�洢�ñߵ�Ȩ��
	struct ArcNode *next;//ָ����һ���ߵ�ָ����
}ArcNode;

//�洢ͼ�Ķ���
typedef struct VerNode
{
	int data;//�洢�ö��������
	struct ArcNode *firstArc;// �ߵ�ͷָ��
	SElemType indegree;//�ý������
	SElemType flag;//�趨һ����־���ں����ж����·����һ�����Ƕ���
}VerNode, AdjList[MaxVernum];

//�洢ͼ
typedef struct
{
	AdjList adjlist;
	SElemType Arcnum;//�洢ͼ�еıߵ���Ŀ
	SElemType Vernum;//�洢ͼ�еĶ������Ŀ
}ALGraph;


//ջ��˳��洢�ṹ��ʾ
typedef struct SqStack
{
	SElemType *base;                        //ջ�׵�ַ
	SElemType *top;                         //ջ��ָ��
	int stacksize;                          //��ǰ�Ѿ�����Ĵ洢�ռ�
}SqStack;

//����һ����ջ
int InitStack(SqStack &S)
{
	//Ϊջ�׷ַ���һ��ָ����С�Ĵ洢�ռ�
	(S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(S).base)
		exit(0);
	(S).top = (S).base;                   //ջ����ջ��ָ����ͬ
	(S).stacksize = STACK_INIT_SIZE;
	return 1;
}



//��ջSΪ��ջ��ջ��ָ���ջ��ָ����ͬ��, �򷵻�1�����򷵻�0
int StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}


//����Ԫ��eΪ�µ�ջ��Ԫ��
int Push(SqStack *S, SElemType e)
{
	if ((*S).top - (*S).base >= (*S).stacksize)
	{
		(*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)
			exit(0);
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*((*S).top)++ = e;
	return 1;
}




//��ջ��Ϊ�գ���ɾ��Sջ��Ԫ����e������ֵ��������1�����򷵻�0
int Pop(SqStack *S, SElemType &e)
{
	if ((*S).top == (*S).base)
	{
		return 0;
	}
	e = *--(*S).top;
	return 1;
}
void Finedegree(ALGraph *G)
{
	int j = 0;
	for (j = 0; j<G->Vernum; j++)
	{

		degree[j] = G->adjlist[j].indegree;
		//printf("��%d�����㼴%c���Ϊ:%d\n", j + 1, G->adjlist[j].data, degree[j]);
	}
}
//����ͼ��G�����ڽӱ�洢�ṹ����G�޻�·�������G�Ķ����һ�����˽ṹ
int TopologicalSort(ALGraph *G)
{
	int i, k;
	int count = 0;
	SqStack S;
	ArcNode *p;
	int e = 0;
	int j = 0;
	p = NULL;
	InitStack(S);
	Finedegree(G);
	for (i = 0; i<G->Vernum; i++)
	{
		if (!degree[i])
			Push(&S, i);//�����Ϊ��Ľڵ�ѹջ
	}
	printf("������������:\n");
	while (!StackEmpty(S))//ֻҪջ���ǿյľ�һֱ����
	{
		Pop(&S, i);//ջ���ǿյ��Ǿͽ���ߵ�һ����ջȻ�����
		printf("%d", G->adjlist[i].data);
		count++;
		for (p = G->adjlist[i].firstArc; p; p = p->next)
		{
			k = p->Ver;
			if (!(--degree[k]))
				Push(&S, k);


		}
	}
	if (count < G->Vernum)
	{

		printf("����������ͼ���ڻ���������������");
		return 0;
	}
	printf("\n");
	return 0;
}


int IfArc(ALGraph *G,int a)//����û��ٴ����붥���Ƿ���ͼ��
{
	int i = 0;
	for (i = 0; i < G->Vernum; i++)
	{
		if (a==G->adjlist[i].data)
			return i;//�������Ķ����ͼ��ĳһ������ֵ��ͬ���ظö�����ͼ�е�λ�ã�return i֮��Ͳ�����ִ�к���֮�������
	}
	return -1;//���forѭ������֮��û���ҵ���Ӧ��ֵ��ô��������ֵΪ-1

}
//���캯�� ����ͼ
void CreateALGraph(ALGraph *G)
{
	int  v1;
	int v2;
	int i = 0;
	int w = 0;
	int m = 0;
	int n = 0;
	ArcNode *p;
	printf("�����������齨ͼ�Ķ��������ͻ�������:\n");
	scanf("%d %d", &G->Vernum, &G->Arcnum);
	for (i = 0; i < G->Vernum; i++)//��ʼ��ͼ�еĶ�����Ϣ
	{
		fflush(stdin);//��ջ��������⽫��һ���Ŀո�س�����Ϣ����
		printf("�������%d������", i + 1);
		scanf("%s", &G->adjlist[i].data);//�����ж������ݽ��г�ʼ��
		G->adjlist[i].firstArc = NULL;//��ÿ�������ͷָ�룬�Լ���ȳ�ʼ��
		G->adjlist[i].flag = 0;
		G->adjlist[i].indegree = 0;

	}
	system("cls");
	
	for (i = 0; i < G->Arcnum; i++)//��ʼ��ͼ�еĻ�����Ϣ
	{

		printf("������ǰ����\n");
		scanf("%d ", &v1);
		printf("������󶥵�\n");
		scanf("%d ", &v2);
		printf("hahaha");
		m = IfArc(G, v1);
		n = IfArc(G, v2);
		p = (ArcNode*)malloc(sizeof(ArcNode));//��p���пռ�������Ĵ�С��һ��ArcNode�ṹ��Ĵ�С
		p->Ver = n;//������Ϣ
		p->next = G->adjlist[m].firstArc;//���ո����������������������
		G->adjlist[m].firstArc = p;
		G->adjlist[n].indegree++;
	}
	system("cls");

}

//��ؼ�·�����ؼ������

void menu()
{
	printf("************************************\n");
	printf("********��ѡ����Ҫʵ�ֵĹ���********\n");
	printf("*************1.��������*************\n");
	printf("*************2.�ؼ�·��*************\n");
	printf("*************0.�˳�ϵͳ*************\n");
	printf("************************************\n");
	printf("******�밴��Ӧ���ְ�ť�Իس�����****\n");
}
int  main()
{
	int set = 0;
	ALGraph G;
	menu();
	scanf("%d", &set);
	while (set)
	{
		switch (set)
		{

		case 1:
			CreateALGraph(&G);
			TopologicalSort(&G);
			break;

		case 2:
			CreateALGraph(&G);
			break;
		default:
			printf("�����������������\n");
			break;
		}
		menu();
		scanf("%d", &set);
	}

	system("pause");
	return 0;
            }
