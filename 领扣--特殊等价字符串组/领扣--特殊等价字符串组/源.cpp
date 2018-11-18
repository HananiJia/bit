#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

//class Solution {
//public:
//	int numSpecialEquivGroups(vector<string>& A) {
//		set<vector<int>> ret;
//		for (int i = 0; i < A.size(); i++)
//		{
//			vector<int>temp;
//			for (int j = 0; j < A[i].size(); j++)
//			{
//				temp.push_back(A[i][j] - '0');
//			}
//			sort(temp.begin(),temp.end());
//		}
//	}
//};

class Solution {
public:
	int numSpecialEquivGroups(vector<string>& A) {
		set<string> ret;
		for (int i = 0; i < A.size(); i++)
		{
			sort(A[i].begin(), A[i].end());
			ret.insert(A[i]);
		}
		return ret.size();
	}
};