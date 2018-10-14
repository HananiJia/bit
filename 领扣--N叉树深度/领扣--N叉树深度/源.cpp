#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};

class Solution {
public:
	int maxDepth(Node* root) {
		if (root == NULL)
			return 0; 
		int i = 0;
		int length = root->children.size();
		int max = 0;
		while (i < length)
		{
			int d=maxDepth(root->children[i]);
			if (d>max)
				max = d;
			i++;
		}
		return max + 1;

	}
};
class Solution {
public:
	int maxDepth(Node* root) {
		if (root == NULL)
			return 0;
		queue<Node*> tree;
		int ret = 0;
		tree.push(root);
		while (!tree.empty())
		{
			int n = tree.size();
			int j = 0;
			for (; j < n; j++)
			{
				Node* now = tree.front();
				tree.pop();
				int i = 0;
				int length = now->children.size();
				while (i < length)
				{
					tree.push(now->children[i]);
					i++;
				}
			}
			ret++;
		}
		return ret;
	}
};