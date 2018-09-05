#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return true;
		return Symmetrical(pRoot,pRoot);
	}
	bool Symmetrical(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (pRoot1 == NULL&&pRoot2 == NULL)//������û��ȥ˵��������һ�����������ǿյ�
			return true;
		if (pRoot1 == NULL || pRoot2 == NULL)
		{
			return false;//�����Ļ�˵�������������ǿգ�������һ���ǿյ����Է��ش���
		}
		//��������˵�����������ǿգ������ж����������Ⱦͼ��������жϣ��������Ⱦͷ��ش���
		if (pRoot1->val != pRoot2->val)
		{
			//���������ǿյ���ֵ��һ��˵���Ǵ����
			return false;
		}
		//�ߵ�����˵����������Ϊ�ղ���ֵ����Ǿ�Ҫȥ�Ƚ����ǵĺ���
		return (Symmetrical(pRoot1->left, pRoot2->right) && Symmetrical(pRoot1->right, pRoot2->left));
	}
};