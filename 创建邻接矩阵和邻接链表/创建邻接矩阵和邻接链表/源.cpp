#define _CRT_SECURE_NO_WARNINGS 1

//***************创建邻接矩阵*************
#define  INFINITY INT_MAX //最大值无穷大
#define MAX_VERTEX_NUM 20//假设存储的最大顶点数
typedef enum{DG,DN,AG,AN} GraphKind;
typedef struct ArcCell //弧结点的定义
{
	VRType adj; //边
	InfoType *info;//入度
}ArcCell, AdjMatrix[MAX_VERTEX_NUM];//用这个数组来存储这个图
typedef strucr{//对图的定义
	VertexType vexs[MAX_VERTEX_NUM];//数组用来存储所有图的顶点
	AdjMatrix arcs;//邻接矩阵
	int Vernum, arcnum;//顶点的总数 ，弧的总数
	GraphKind kind;//图的种类标志
}


//***************创建邻接表*************
typedef struct ArcNode //邻接表中的表结点
{
	int adjvex;//邻接点域，存放于Vi邻接的点在表头数组中的位置
	struct ArcNode *nextarc;//链域，指示下一条边
	int weight;//权重
}ArcNode ;
//头结点
typedef struct VNode{
	vertex data;//存放顶点信息
	ArcNode *firstarc;//指向第一个邻接点
}Vnode, AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;//表头向量
	int vernum, arcnum;//存放顶点数和边的数目
	int kind;//图的种类标志
}ALGraph;