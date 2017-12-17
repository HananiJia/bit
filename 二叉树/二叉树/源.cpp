#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

/*二叉树节点数据结构*/
typedef struct TreeNode{
	ElemType data;
	struct TreeNode *lChild;
	struct TreeNode *rChild;
} TreeNode;

/*使用先序遍历创建二叉树*/
TreeNode *createBiTreeInPreOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//这样调用scanf函数时,树的节点一次全部输入,如果要一次输入一个的话,那么在格式化字符串%ch前面加上空格即可
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("内存空间不足,程序退出\n");
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

/*使用中序遍历创建二叉树*/
TreeNode *createBiTreeInInOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//这样调用scanf函数时,树的节点一次全部输入,如果要一次输入一个的话,那么在格式化字符串%ch前面加上空格即可
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("内存空间不足,程序退出\n");
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

/*使用后序遍历创建二叉树*/
TreeNode *createBiTreeInPostOrder(){
	ElemType ch;
	TreeNode *T;

	scanf("%ch", &ch);	//这样调用scanf函数时,树的节点一次全部输入,如果要一次输入一个的话,那么在格式化字符串%ch前面加上空格即可
	if (ch != '#'){
		T = (TreeNode *)malloc(sizeof(TreeNode));
		if (T == NULL){
			printf("内存空间不足,程序退出\n");
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

/*先序遍历*/
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

/*中序遍历*/
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

/*先序遍历*/
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