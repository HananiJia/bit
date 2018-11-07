#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int longestMountain(vector<int>& A) {
//		int length = 0;
//		int max = length;
//		int flag = 0;//0����ƽ�� 1�������� -1�����½�
//		int grow = 0;//0����������1��������
//		for (int i = 0; i < A.size()-1; i++)
//		{
//			if (A[i] < A[i + 1])//����������
//			{
//				if (flag == -1)//֮ǰ���½�
//				{
//					grow = 1;
//				}
//				flag = 1;
//			}
//			if (A[i] == A[i + 1])//����ƽ��
//			{
//				flag = 0;
//				grow = 0;
//			}
//			if (A[i]>A[i + 1])//�����½�
//			{
//				if (flag == 1)//����֮ǰ������
//				{
//					grow = 1;
//				}
//				if (flag == -1)
//				{
//					grow = 1;
//				}
//				flag = -1;
//			}
//			if (grow)
//			{
//				length++;
//			}
//			else
//			{
//				//��ʱ�������˾�Ҫ�������ڵĳ��Ⱥ���ǰ���ĸ���
//				if (length > max)
//				{
//					max = length;
//				}
//				else
//				{
//					length = 0;
//				}
//			}
//		}
//		if (length > max)
//			max = length;
//		return max;
//	}
//};

class Solution {
public:
	int longestMountain(vector<int>& A) {
		if (A.size() <= 2)
			return 0;
		int max = 0;
		int length = 0;
		for (int i = 0; i < A.size() - 1; i++)
		{
			if (A[i + 1]>A[i])//��ʼ����������������ɽ����һ�����
			{
				length = FindLongth(A, i);
			}
			if (length > max)
			{
				max = length;
			}
		}
		return max;
	}
	int FindLongth(vector<int>& A, int pos)
	{
		int flag = 0;//����û��ʼ�½�
		int length = 0;
		for (int i = pos; i < A.size() - 1; i++)
		{
			length++;
			if (A[i + 1] < A[i])//����ʼ�½���
			{
				flag = 1;
			}
			if (flag == 1 && (A[i] == A[i + 1]))//�������½���ƽ�˾�Ҫ������
			{
				return length;
			}
			if (flag == 0 && A[i] == (A[i + 1]))//û�������½�ƽ�˾�Ҫ����0
			{
				return 0;
			}
			if (flag == 1 && (A[i] < A[i + 1]))//�������½���������ҲҪ������
			{
				return length;
			}
		}
		if (flag == 0)
			return 0;
		if (A[A.size() - 1]<A[A.size() - 2])
			length++;
		return length;
	}
};
int main()
{
	Solution A;
	vector<int> a = {2, 1, 4, 7, 3, 2, 5 };
	int m=A.longestMountain(a);
	cout << m << endl;
	system("pause");
	return 0;
}