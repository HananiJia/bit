#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//class Solution {
//public:
//	int longestMountain(vector<int>& A) {
//		int length = 0;
//		int max = length;
//		int flag = 0;//0代表平衡 1代表上升 -1代表下降
//		int grow = 0;//0代表不增长，1代表增长
//		for (int i = 0; i < A.size()-1; i++)
//		{
//			if (A[i] < A[i + 1])//代表在上升
//			{
//				if (flag == -1)//之前是下降
//				{
//					grow = 1;
//				}
//				flag = 1;
//			}
//			if (A[i] == A[i + 1])//代表平衡
//			{
//				flag = 0;
//				grow = 0;
//			}
//			if (A[i]>A[i + 1])//代表下降
//			{
//				if (flag == 1)//代表之前是上升
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
//				//这时候不增长了就要看看现在的长度和以前的哪个大
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
			if (A[i + 1]>A[i])//开始上升了这个点可能是山脉的一个起点
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
		int flag = 0;//代表还没开始下降
		int length = 0;
		for (int i = pos; i < A.size() - 1; i++)
		{
			length++;
			if (A[i + 1] < A[i])//代表开始下降了
			{
				flag = 1;
			}
			if (flag == 1 && (A[i] == A[i + 1]))//经历过下降了平了就要返回了
			{
				return length;
			}
			if (flag == 0 && A[i] == (A[i + 1]))//没经历过下降平了就要返回0
			{
				return 0;
			}
			if (flag == 1 && (A[i] < A[i + 1]))//经历过下降又上升了也要返回了
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