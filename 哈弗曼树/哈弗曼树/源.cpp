#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
	int weight;
	int parent, lchild, rchild;
	int total;
}HTNode, *HuffmanTree;               //��̬��������洢�շ�����

typedef char **HuffmanCode;          //��̬��������洢�շ���������


int min(HuffmanTree &ht, int a1);              //��������
void Select(HuffmanTree &H, int a, int &s1, int &s2);         //��������
void CreatHuffmanTree(HuffmanTree &HT1, int *w, int n) {
	//w���n���ַ���Ȩֵ������շ�����HT1
	int i = 0;
	int m = 0;
	m = 2 * n - 1;
	if (n <= 1) {                          //�жϴ�������Ƿ����������ʽ
		printf("�����ַ���������...\n");
		return;
	}
	HT1 = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));      //0���±���
	for (i = 1; i <= n; ++i) {             //��ʼ���շ�����
		HT1[i].weight = w[i - 1];
		HT1[i].parent = 0;
		HT1[i].lchild = 0;
		HT1[i].rchild = 0;
		HT1[i].total = 0;
	}
	for (; i <= m; ++i) {                                //��ʼ���շ�������Ҷ��
		HT1[i].weight = 0;
		HT1[i].parent = 0;
		HT1[i].lchild = 0;
		HT1[i].rchild = 0;
		HT1[i].total = 0;
	}
	for (i = n + 1; i <= m; ++i) {                            //��ʼ���շ�������Ҷ�ӵ��������
		int s1, s2;
		Select(HT1, i - 1, s1, s2);              //ѡ����
		HT1[s1].parent = i;
		HT1[s2].parent = i;
		HT1[i].lchild = s1;
		HT1[i].rchild = s2;
		HT1[i].weight = HT1[s1].weight + HT1[s2].weight;
	}
}

void Select(HuffmanTree &H, int a, int &ss1, int &ss2) {	// ��HT1[1...i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2
	ss1 = min(H, a);
	ss2 = min(H, a);
}

int min(HuffmanTree &ht, int a1) {                 //Ѱ��Ȩֵ��С�Ľڵ�λ�ã�����min����
	int i, min, min_weight;
	min = 2147483647;
	min_weight = 2147483647;
	for (i = 1; i <= a1; i++) {
		if ((ht[i].weight < min_weight) && (ht[i].total == 0)) {       //�������Ȩֵ����min_weight�ұ�־��Ϣtotal����0
			min_weight = ht[i].weight;                            //�ͽ���СȨֵ����С���λ����Ϣ�ı䣬����Ƚ���һ���ڵ�
			min = i;
		}
	}
	ht[min].total = 1;             //�������ҵ�����С���λ�õı�־��Ϣ�޸�
	return min;
}


void CodingHuffman(HuffmanTree &HT1, HuffmanCode &HC1, int n) {
	HC1 = (HuffmanCode)malloc(n*sizeof(char *));           //����n���ַ������ͷָ������
	if (!HC1) {           //�쳣����
		printf("HuffmanCode malloc faild!");
		exit(-1);
	}
	char *cd = (char *)malloc(n*sizeof(char));          //���������Ĺ�������
	if (!cd) {           //�쳣����
		printf("code malloc faild!");
		exit(-1);
	}
	cd[n - 1] = '\0';                        //���������
	int i;
	for (i = 1; i <= n; i++) {                //����ַ���շ�������
		int start = n - 1;                   //���������λ��
		int c, f;
		for (c = i, f = HT1[i].parent; f != 0; c = f, f = HT1[f].parent)    //��Ҷ�ӵ������������
		if (HT1[f].lchild == c)
			cd[--start] = '0';
		else cd[--start] = '1';
		HC1[i] = (char *)malloc((n - start) * sizeof(char));         //Ϊ��i���ַ��������ռ�
		strcpy(HC1[i], &cd[start]);                  //��cd���Ʊ��루������HC
	}
	free(cd);                      //�ͷŹ����ռ�
}

void PrintHuffmanCode(HuffmanTree HT1, HuffmanCode &HC1, int n) {
	int i;
	printf("���	Ȩֵ	�շ�������\n");
	for (i = 1; i <= n; i++) {
		printf("%d	%d	%s\n", i, HT1[i].weight, HC1[i]);
		//	printf("\n\n");
	}
}

void PrintHuffman(HuffmanTree HT1, int n) {
	int i;
	printf("���	weight	parent	lchild	rchild\n");
	for (i = 1; i <= 2 * n - 1; i++) {
		printf("%d	%d	%d	%d	%d\n", i, HT1[i].weight, HT1[i].parent, HT1[i].lchild, HT1[i].rchild);
	}
}

int main() {
	int n, *w;
	int i;
	printf("������Ҷ�ӵĸ���(����1)��");
	scanf("%d", &n);
	w = (int *)malloc(n * sizeof(int));
	printf("���������Ҷ�ӵ�Ȩֵ��\n");
	for (i = 0; i < n; i++) {
		printf("�������%d��Ҷ�ӵ�Ȩ��", i + 1);
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