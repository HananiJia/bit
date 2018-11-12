#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	int numTrees(int n) {
//		if (n == 1 || n == 0)
//			return 1;
//		int sum = 0;
//		for (int i = 1; i <= n; i++)
//		{
//			int left = numTrees(i - 1);
//			int right = numTrees(n - i);
//			int num = left*right;
//			sum += num;
//		}
//		return sum;
//	}
//};
class Solution {
public:
	int numTrees(int n) {
		vector<int> ret(2, 1);
		ret.resize(n + 1);
		for (int i = 2; i <= n; i++)
		{
			//ǰ��������Ҫ����
			int sum = 0;
			for (int j = 0; j < i; j++)//����ж��ٸ����ӽ��
			{
				ret[i] += ret[j] * ret[i - 1-j];//�������
			}
		}
		return ret[n];
	}
};



int main()
{
	Solution A;
	cout << A.numTrees(5) << endl;
	system("pause");
	return 0;
}