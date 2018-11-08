#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty())
			return 0;
		if (duration == 0)
			return 0;
		int sum = 0;//中毒时间
		int time = 0;//花费时间
		sum += duration;
		time =timeSeries[0]+duration;
		for (int i = 1; i < timeSeries.size(); i++)
		{
			if (time >= timeSeries[i])
			{
				sum = sum - (time - timeSeries[i]);
				sum += duration;
				time = timeSeries[i] + duration;
			}
			else
			{
				sum += duration;
				time = timeSeries[i] + duration;
			}
		}
		return sum;
	}
};

int main()
{
	Solution A;
	vector<int> a = { 1, 2};
	int dura = 2;
	int num=A.findPoisonedDuration(a, dura);
	cout << num << endl;
	system("pause");
	return 0;
}