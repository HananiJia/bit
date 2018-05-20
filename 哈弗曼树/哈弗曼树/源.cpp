#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
	int weight;
	int parent, lchild, rchild;
	int total;
}HTNode, *HuffmanTree;               //动态分配数组存储赫夫曼树

typedef char **HuffmanCode;          //动态分配数组存储赫夫曼树编码


int min(HuffmanTree &ht, int a1);              //函数声明
void Select(HuffmanTree &H, int a, int &s1, int &s2);         //函数声明
void CreatHuffmanTree(HuffmanTree &HT1, int *w, int n) {
	//w存放n个字符的权值，构造赫夫曼树HT1
	int i = 0;
	int m = 0;
	m = 2 * n - 1;
	if (n <= 1) {                          //判断传入参数是否符合树的形式
		printf("存入字符个数出错...\n");
		return;
	}
	HT1 = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));      //0号下表不用
	for (i = 1; i <= n; ++i) {             //初始化赫夫曼树
		HT1[i].weight = w[i - 1];
		HT1[i].parent = 0;
		HT1[i].lchild = 0;
		HT1[i].rchild = 0;
		HT1[i].total = 0;
	}
	for (; i <= m; ++i) {                                //初始化赫夫曼树的叶子
		HT1[i].weight = 0;
		HT1[i].parent = 0;
		HT1[i].lchild = 0;
		HT1[i].rchild = 0;
		HT1[i].total = 0;
	}
	for (i = n + 1; i <= m; ++i) {                            //初始化赫夫曼树除叶子的其他结点
		int s1, s2;
		Select(HT1, i - 1, s1, s2);              //选择函数
		HT1[s1].parent = i;
		HT1[s2].parent = i;
		HT1[i].lchild = s1;
		HT1[i].rchild = s2;
		HT1[i].weight = HT1[s1].weight + HT1[s2].weight;
	}
}

void Select(HuffmanTree &H, int a, int &ss1, int &ss2) {	// 在HT1[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2
	ss1 = min(H, a);
	ss2 = min(H, a);
}

int min(HuffmanTree &ht, int a1) {                 //寻找权值最小的节点位置，并用min返回
	int i, min, min_weight;
	min = 2147483647;
	min_weight = 2147483647;
	for (i = 1; i <= a1; i++) {
		if ((ht[i].weight < min_weight) && (ht[i].total == 0)) {       //如果结点的权值大于min_weight且标志信息total等于0
			min_weight = ht[i].weight;                            //就将最小权值和最小结点位置信息改变，否则比较下一个节点
			min = i;
		}
	}
	ht[min].total = 1;             //最后把已找到的最小结点位置的标志信息修改
	return min;
}


void CodingHuffman(HuffmanTree &HT1, HuffmanCode &HC1, int n) {
	HC1 = (HuffmanCode)malloc(n*sizeof(char *));           //分配n个字符编码的头指针向量
	if (!HC1) {           //异常处理
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *cd = (char *)malloc(n*sizeof(char));          //分配求编码的工作区间
	if (!cd) {           //异常处理
		printf("code malloc faild!");
		exit(-1);
	}
	cd[n - 1] = '\0';                        //编码结束符
	int i;
	for (i = 1; i <= n; i++) {                //逐个字符求赫夫曼编码
		int start = n - 1;                   //编码结束符位置
		int c, f;
		for (c = i, f = HT1[i].parent; f != 0; c = f, f = HT1[f].parent)    //从叶子到根逆向求编码
		if (HT1[f].lchild == c)
			cd[--start] = '0';
		else cd[--start] = '1';
		HC1[i] = (char *)malloc((n - start) * sizeof(char));         //为第i个字符编码分配空间
		strcpy(HC1[i], &cd[start]);                  //从cd复制编码（串）到HC
	}
	free(cd);                      //释放工作空间
}

void PrintHuffmanCode(HuffmanTree HT1, HuffmanCode &HC1, int n) {
	int i;
	printf("编号	权值	赫夫曼编码\n");
	for (i = 1; i <= n; i++) {
		printf("%d	%d	%s\n", i, HT1[i].weight, HC1[i]);
		//	printf("\n\n");
	}
}

void PrintHuffman(HuffmanTree HT1, int n) {
	int i;
	printf("编号	weight	parent	lchild	rchild\n");
	for (i = 1; i <= 2 * n - 1; i++) {
		printf("%d	%d	%d	%d	%d\n", i, HT1[i].weight, HT1[i].parent, HT1[i].lchild, HT1[i].rchild);
	}
}

int main() {
	int n, *w;
	int i;
	printf("请输入叶子的个数(大于1)：");
	scanf("%d", &n);
	w = (int *)malloc(n * sizeof(int));
	printf("请输入各个叶子的权值：\n");
	for (i = 0; i < n; i++) {
		printf("请输入第%d个叶子的权：", i + 1);
		scanf("%d", &*(w + i));
	}

	HuffmanTree HT;
	HuffmanCode HC;
	CreatHuffmanTree(HT, w, n);
	printf("\n\n\n");
	PrintHuffman(HT, n);
	printf("\n\n\n");
	CodingHuffman(HT, HC, n);
	PrintHuffmanCode(HT, HC, n);
	return 0;
}