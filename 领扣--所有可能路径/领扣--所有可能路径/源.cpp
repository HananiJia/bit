#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> ret;
		int num = graph.size() - 1;
		vector<int> path;
		AllPath(graph, ret,path,0,num);
		return ret;
	}
	void AllPath(vector<vector<int>>& graph, vector<vector<int>>& ret, vector<int>& path,int begin,int num)
	{
		path.push_back(begin);
		if (begin == num)
		{
			ret.push_back(path);
			return;
		}
		for (int i = 0; i < graph[begin].size(); i++)
		{
			AllPath(graph, ret, path, graph[begin][i], num);
		}
		return;
	}
};