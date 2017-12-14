#define _CRT_SECURE_NO_WARNINGS 1

//***************�����ڽӾ���*************
#define  INFINITY INT_MAX //���ֵ�����
#define MAX_VERTEX_NUM 20//����洢����󶥵���
typedef enum{DG,DN,AG,AN} GraphKind;
typedef struct ArcCell //�����Ķ���
{
	VRType adj; //��
	InfoType *info;//���
}ArcCell, AdjMatrix[MAX_VERTEX_NUM];//������������洢���ͼ
typedef strucr{//��ͼ�Ķ���
	VertexType vexs[MAX_VERTEX_NUM];//���������洢����ͼ�Ķ���
	AdjMatrix arcs;//�ڽӾ���
	int Vernum, arcnum;//��������� ����������
	GraphKind kind;//ͼ�������־
}


//***************�����ڽӱ�*************
typedef struct ArcNode //�ڽӱ��еı���
{
	int adjvex;//�ڽӵ��򣬴����Vi�ڽӵĵ��ڱ�ͷ�����е�λ��
	struct ArcNode *nextarc;//����ָʾ��һ����
	int weight;//Ȩ��
}ArcNode ;
//ͷ���
typedef struct VNode{
	vertex data;//��Ŷ�����Ϣ
	ArcNode *firstarc;//ָ���һ���ڽӵ�
}Vnode, AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;//��ͷ����
	int vernum, arcnum;//��Ŷ������ͱߵ���Ŀ
	int kind;//ͼ�������־
}ALGraph;