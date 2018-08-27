#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//struct TreeNode {
//int val;
//struct TreeNode *left;
//struct TreeNode *right;
//TreeNode(int x) :
//val(x), left(NULL), right(NULL) {
//}
//};
//class Solution {
//public:
//	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
//	{
//		if (pRoot1 == NULL && pRoot2 != NULL)
//			return false;
//		if (pRoot1 != NULL && pRoot2 == NULL)
//			return false;
//		if (pRoot1 == NULL && pRoot2 == NULL)
//			return true;
//		else
//			return (HasSubtree(pRoot1->left, pRoot2->left) && (HasSubtree(pRoot1->right, pRoot2->right)));
//		
//	}
//};



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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL&&pRoot2 != NULL)
		{
			//��ʱ���Ҫȥ�Ҵ��������û����������ĸ�
			if (pRoot1->val == pRoot2->val)
			{
				result = FindHasSubtree(pRoot1, pRoot2);
				//��ʱ���Ҫ��ʼ�Ա����������ǲ���һ���ˣ���һ�������¶Ա�
			}
				//��ʱ�����������㲻һ���Ǿ͵�ȥ�������ӻ����Һ���������ң����������õݹ�ȽϺ�
				//��������Ҫ���浱ǰ���λ�ã��������û�еĻ����˵���ǰ����ȥ���Һ���
			if (!result)
			{
				result = HasSubtree(pRoot1->left, pRoot2);//�����㲻�Ǿ�ȥ�������������
			}
			if (!result)
			{
				result = HasSubtree(pRoot1->right, pRoot2);//����û�ҵ���ȥ�Һ��������
			}
		}
		return result;
	}
	bool FindHasSubtree(TreeNode *p1, TreeNode *p2)
	{
		//������������Ա����������ǲ���һ���������õݹ�
		if (p2 == NULL)//���2��ͷ����ʱ��˵��ƥ�����˻�û�з��ش����ֵ�Ǿ�����ȷ��
			return true;
		if (p1 == NULL)//���2��û�е���1�����ˣ���˵����ƥ��
			return false;
		if (p1->val != p2->val)//��������ֵ��һ��˵����ƥ��
			return false;
		//�ߵ�����˵������1���ǿ�2Ҳ���ǿղ���������ֵһ�����Ǿ�ȥ�Ƚ����������ĺ���һ����һ��һ��һ��ݹ�
		return (FindHasSubtree(p1->left, p2->left) && FindHasSubtree(p1->right, p2->right));
	}
};


bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL)
		return false;
	if (pRoot1->val == pRoot2->val)
		return true;
	//����˵�������ڵ㲻��ͬ����Ҫȥ���������
	return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
}