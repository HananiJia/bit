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

//class Solution {
//public:
//	vector<int> postorder(Node* root) {
//		vector<int> ret;
//		Postorder(root, ret);
//		return ret;
//	}
//	void Postorder(Node* root, vector<int> &a)
//	{
//		if (root == NULL)
//			return;
//		for (int i = 0; i < root->children.size(); i++)
//		{
//			Postorder(root->children[i]);
//		}
//		a.push_back(root->val);
//		return;
//	}
//};

class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> ret;
		if (root == NULL)
			return ret;
		stack<Node*> tree;
		tree.push(root);
		while (!tree.empty())
		{
			Node *cur = tree.top();
			tree.pop();
			for (int i = 0; i < cur->children.size(); i++)
			{
				tree.push(cur->children[i]);
			}
			ret.push_back(cur->val);
		}
		int left = 0;
		int right = ret.size() - 1;
		while (left <= right)
		{
			int temp = ret[left];
			ret[left] = ret[right];
			ret[right] = temp;
			left++;
			right--;
		}
		return ret;
	}
};