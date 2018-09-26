#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> arr;
		if (pRoot == NULL)
			return arr;
		queue<TreeNode*> tree;
		tree.push(pRoot);
		while (!tree.empty())
		{
			int n = tree.size();
			vector<int> temp;
			for (int i = 1; i <= n; i++)
			{
				
				TreeNode *temp1 = tree.front();
				tree.pop();
				temp.push_back(temp1->val);
				if (temp1->left )
				{
					tree.push(temp1->left);
				}
				if (temp1->right )
				{
					tree.push(temp1->right);
				}
			}
			arr.push_back(temp);

		}
		return arr;

	}

};