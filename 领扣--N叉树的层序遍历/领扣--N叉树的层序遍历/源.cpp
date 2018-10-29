#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;



class Node {
public:
int val = NULL;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		vector < vector<int>> ret;
		int level = 1;
		Levelorder(ret, level, root);
		return ret;
	}
	void Levelorder(vector<vector<int>>& ret, int level, Node* root)
	{
		if (root == NULL)
			return;
		int size = ret.size();
		if (size < level)
		{
			vector<int> temp;
			ret.push_back(temp);
		}
		ret[level - 1].push_back(root->val);
		for (int i = 0; i < root->children.size(); i++)
		{
			Levelorder(ret, level + 1, root->children[i]);
		}
		return ;
	}
};