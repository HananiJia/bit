#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty())//����ǿյ���ô������ֵ�ͽ���if�������
			return false;//�������˵���������ǿյ�ֱ�ӷ��ش���Ϳ���
		int row = 0;//���ϱ�һ��
		int col = array[0].size() - 1;//���ұ�һ��
		while (col >= 0 && row < array.size())
		{
			if (target < array[row][col])
				col--;
			else
			{
				if (target>array[row][col])
				{
					row++;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
};