#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rotatedDigits(int N) {
		int count = 0;
		for (int i = 1; i <= N; i++)
		{
			if (IsOrNum(i))
				count++;
		}
		return count;
	}
	bool IsOrNum(int num)
	{
		vector<int> change = { 0, 1, 5, -1, -1, 2, 9, -1, 8, 6 };
		vector<int> numv1;
		while (num > 0)
		{
			int n = num % 10;
			numv1.push_back(n);
			num = num / 10;
		}
		vector<int> numv2;
		for (int i = 0; i < numv1.size(); i++)
		{
			int n = change[numv1[i]];
			if (n == -1)
				return false;
			numv2.push_back(n);
		}
		for (int i = 0; i < numv1.size(); i++)
		{
			if (numv1[i] != numv2[i])
				return true;
		}
		return false;
	 }
};
int main()
{
	Solution A;
	cout<<A.rotatedDigits(857);
	system("pause");
	return 0;
}