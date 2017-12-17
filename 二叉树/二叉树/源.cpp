#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

/*�������ڵ����ݽṹ*/
typedef struct TreeNode{
	ElemType data;
	struct TreeNode *lChild;
	struct TreeNode *rChild;
} TreeNode;

/*ʹ�������������������*/
TreeNode *createBiTreeInPreOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//��������scanf����ʱ,���Ľڵ�һ��ȫ������,���Ҫһ������һ���Ļ�,��ô�ڸ�ʽ���ַ���%chǰ����Ͽո񼴿�
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("�ڴ�ռ䲻��,�����˳�\n");
			exit(-1);
		}
		T->data = ch;
		T->lChild = createBiTreeInPreOrder();
		T->rChild = createBiTreeInPreOrder();
	}
	else{
		T = NULL;
	}

	return T;
}

/*ʹ�������������������*/
TreeNode *createBiTreeInInOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//��������scanf����ʱ,���Ľڵ�һ��ȫ������,���Ҫһ������һ���Ļ�,��ô�ڸ�ʽ���ַ���%chǰ����Ͽո񼴿�
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("�ڴ�ռ䲻��,�����˳�\n");
			exit(-1);
		}
		T->lChild = createBiTreeInInOrder();
		T->data = ch;
		T->rChild = createBiTreeInInOrder();
	}
	else{
		T = NULL;
	}

	return T;
}

/*ʹ�ú����������������*/
TreeNode *createBiTreeInPostOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//��������scanf����ʱ,���Ľڵ�һ��ȫ������,���Ҫһ������һ���Ļ�,��ô�ڸ�ʽ���ַ���%chǰ����Ͽո񼴿�
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("�ڴ�ռ䲻��,�����˳�\n");
			exit(-1);
		}
		T->lChild = createBiTreeInPostOrder();
		T->rChild = createBiTreeInPostOrder();
		T->data = ch;
	}
	else{
		T = NULL;
	}

	return T;
}

/*�������*/
void PreOrderTraverse(TreeNode *T)
{
	ElemType data;
	if (T != NULL)
	{
		data = T->data;
		printf("%c ", data);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

/*�������*/
void InOrderTraverse(TreeNode *T)
{
	ElemType data;
	if (T != NULL)
	{
		data = T->data;
		InOrderTraverse(T->lChild);
		printf("%c ", data);
		InOrderTraverse(T->rChild);
	}
}

/*�������*/
void PostOrderTraverse(TreeNode *T)
{
	ElemType data;
	if (T != NULL)
	{
		data = T->data;
		PostOrderTraverse(T->lChild);
		PostOrderTraverse(T->rChild);
		printf("%c ", data);
	}
}



int main(void){
	char ch;

	TreeNode *tree;
	tree = createBiTreeInPreOrder();

	PreOrderTraverse(tree);

	scanf("%c", &ch);
	scanf("%c", &ch);
	return 0;
}