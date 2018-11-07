#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {

		return SquenceBST(sequence, 0, sequence.size() - 1);
	}
	bool SquenceBST(const vector<int>& a, int start, int end)
	{
		if (a.empty())
			return false;
		if (start > end)
			return false;
		int middle = a[end];
		int pos = -1;
		for (int i = start; i < end; i++)
		{
			if (a[i]>middle)
			{
				pos = i;
				break;
			}
		}
		for (int i = pos; i < end; i++)
		{
			if (a[i] < middle)
				return false;
		}
		return SquenceBST(a, start, pos) && SquenceBST(a, pos + 1, end - 1);
	}
};

int main()
{
	Solution A;
	vector<int> a = { 1, 2, 3, 4, 5 };
	if (A.VerifySquenceOfBST(a))
	{
		cout << "true" << endl; 
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}