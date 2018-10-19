#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		for (int i = 1; i <= numRows; i++)
		{
			vector<int> temp;
			for (int n = 0; n < i; n++)
			{
				if (n == 0 || n == i-1)
				{
					temp.push_back(1);
				}
				else
				{
					int m = ret[i - 2][n] + ret[i - 2][n - 1];
					temp.push_back(m);
				}
			}
			ret.push_back(temp);

		}
		return ret;
	}
};
int main()
{
	Solution A;
	vector<vector<int>> c;
	c=A.generate(3);
	for (int i = 0; i < c.size(); i++)
	{
		for (int j = 0; j < c[i].size(); j++)
		{
			cout << c[i][j];
		}
		cout << endl;
	}
	system("pause");

}