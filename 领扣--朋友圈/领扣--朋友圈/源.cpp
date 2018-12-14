#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//class Solution {
//public:
//	int findCircleNum(vector<vector<int>>& M) {
//		int count = 0;
//		for (int i = 0; i < M.size(); i++)
//		{
//			for (int j = 0; j < M[i].size(); j++)
//			{
//				if (M[i][j] == 1)
//				{
//					count++;
//					FindFriend(M, i, j);
//				}
//			}
//		}
//		return count;
//	}
//	void FindFriend(vector < vector<int>> &M, int i, int j)
//	{
//		M[i][j] == 0;
//		if (i > 0 && i < M.size() && M[i - 1][j] == 1)
//		{
//			FindFriend(M, i - 1, j);
//		}
//		if (i >= 0 && i < (M.size()-1) && M[i + 1][j] == 1)
//		{
//			FindFriend(M, i + 1, j);
//		}
//		if (j >= 0 && j < (M[i].size() - 1) && M[i][j + 1] == 1)
//		{
//			FindFriend(M, i, j + 1);
//		}
//		if (j > 0 && j < M[i].size() && M[i][j - 1] == 1)
//		{
//			FindFriend(M, i, j - 1);
//		}
//		return;
//		
//	}
//};

//[[1, 0, 0, 1], 
//[0, 1, 1, 0],
//[0, 1, 1, 1], 
//[1, 0, 1, 1]]



	class Solution {
	public:
		int findCircleNum(vector<vector<int>>& M) {
			int count = 0;
			vector<int> visit(M.size(), 0);
			for (int i = 0; i < M.size(); i++)
			{
				if (visit[i] == 0)
				{
					FindCircle(M, i,visit);
					count++;
				}
			}
			return count;
		}
		void FindCircle(vector<vector<int>>& M, int i,vector<int> &visit)
		{
			for (int j = 0; j < M.size(); j++)
			{
				if (M[i][j] == 1 && visit[j] == 0)
				{
					visit[j] = 1;
					FindCircle(M, j, visit);
				}
			}
		}
	};