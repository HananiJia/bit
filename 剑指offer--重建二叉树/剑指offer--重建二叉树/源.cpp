#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (vin.empty())
			return NULL;
		TreeNode* root = new TreeNode(pre[0]);
		int pos = -1;
		for (int i = 0; i < vin.size(); i++)
		{
			if (vin[i] == pre[0])
			{
				pos =i;
				break;
			}
		}
		vector<int> newprel, newprer, newvinl, newvinr;
		for (int i = 0; i < pos; i++)
		{
			newvinl.push_back(vin[i]);
			newprel.push_back(pre[i + 1]);
		}
		for (int i = pos + 1; i < vin.size(); i++)
		{
			newprer.push_back(pre[i]);
			newvinr.push_back(vin[i]);
		}
		root->left = reConstructBinaryTree(newprel, newvinl);
		root->right = reConstructBinaryTree(newprer, newvinr);
		return root;
	}
};

//class Solution {
//public:
//	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
//
//	}
//};

int main()
{
	Solution A;
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = A.reConstructBinaryTree(pre, vin);
	printf("%d", root->val);

}