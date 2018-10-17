#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int matrixScore(vector<vector<int>>& A) {
//		if (A.size() == 0)
//			return 0;
//		//先判断最高位是不是1不是1翻转
//		for (int i = 0; i < A.size(); i++)
//		{
//			if (A[i][0] != 1)
//			{
//				ReverseV(A,i);
//			}
//		}
//		//后判断如果某一列0比较多翻转
//		for (int i = 0; i < A[0].size(); i++)
//		{
//			int sum = 0;
//			for (int j = 0; j < A.size(); j++)
//			{
//				if (A[i][j] == 0)
//					sum++;
//			}
//			if (sum>(A.size() / 2))
//			{
//				Reversev(A, i);
//			}
//		}
//		int sum = 0;
//		for (int i = 0; i < A.size(); i++)
//		{
//			sum += Sumvector(A[i]);
//		}
//		return sum;
//
//	}
//	void ReverseV(vector<vector<int>>& a,int h)
//	{
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[h][i] == 1)
//				a[h][i] = 0;
//			else
//				a[h][i] = 1;
//		}
//	}
//	void Reversev(vector<vector<int>>& a,int l)//翻转某一列的函数
//	{
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[i][l] == 0)
//				a[i][l] = 1;
//			else
//				a[i][l] = 0;
//		}
//	}
//	int Sumvector(vector<int>& a)
//	{
//		int sum = 0;
//		int n = a.size()-1;
//		for (int i = 0; i < a.size(); i++)
//		{
//			if (a[i] == 1)
//			{
//				sum += pow(2, n);
//			}
//			n--;
//		}
//		return sum;
//	}
//};


class Solution {
public:
	int matrixScore(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i][0] == 0)
			{
				for (int j = 0; j < A[i].size(); j++)
				{
					A[i][j] = 1 - A[i][j];
				}
			}
		}
		for (int i = 0; i < A[0].size(); i++)
		{
			int count = 0;
			for (int j = 0; j < A.size(); j++)
			{
				if (A[j][i] == 0)
					count++;
			}
			if (count>A.size() / 2)
			{
				for (int m = 0; m < A.size(); m++)
				{
					A[m][i] = 1 - A[m][i];
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < A.size(); i++)
		{
			
			for (int j = 0; j < A[i].size(); j++)
			{
				sum += A[i][j] * pow(2, A[i].size() - j - 1);
			}
		}
		return sum;
	}
};