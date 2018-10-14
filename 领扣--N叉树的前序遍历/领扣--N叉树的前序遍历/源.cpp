#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> preorder(Node* root) {
		vector<int> ret;
		Preorder(root,ret);
		return ret;
	}
	void Preorder(Node* root, vector<int>& ret)
	{
		if (root == NULL)
			return;
		ret.push_back(root->val);
		int i = 0;
		int length = root->children.size();
		for (i = 0; i < length; i++)
		{
			Preorder(root->children[i], ret);
		}
	}
};

class Solution {
public:
	vector<int> preorder(Node* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		stack<Node*> tree;
		tree.push(root);
		while (!tree.empty())
		{
			Node* cur = tree.top();
			tree.pop();
			ret.push_back(cur->val);
			int i = 0;
			int length = cur->children.size();
			for (i = length-1; i >= 0; i--)
			{
				tree.push(cur->children[i]);
			}
		}
		return ret;
	}
};