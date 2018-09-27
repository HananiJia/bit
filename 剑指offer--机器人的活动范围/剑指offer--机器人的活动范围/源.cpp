#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *robot = new bool [rows*cols];
		for (int i = 0; i < rows*cols; i++)
		{
			robot[i] = false;
		}
		int count = Moving(threshold, rows, cols, 0, 0, robot);
		delete[] robot;
		return count;
	    
	}
	int Moving(int k, int rows, int cols, int left, int right, bool *robot)
	{
		int count = 0;
		if(GetTorF(k, rows, cols, left, right,robot))
		{
			robot[left*cols + right] = true;
			count = 1 + Moving(k, rows , cols, left-1, right, robot)
				+ Moving(k, rows , cols, left+1, right, robot)
				+ Moving(k, rows, cols , left, right-1, robot)
				+ Moving(k, rows, cols , left, right+1, robot);
		}
		return count;
	}
	bool GetTorF(int k, int rows, int cols, int left, int right, bool *robot)
	{
		int sumleft = Getnum(left);
		int sumright = Getnum(right);
		if (left>=0&&right>=0&&left <= rows&&right <= cols&&sumleft +sumright <= k&&robot[left*cols+right]==false)
			return true;
		else
			return false;
	}
	int Getnum(int n)
	{
		int sum = 0;
		while (n >0)
		{
			sum += n % 10;
			n = n / 10;
		}
		return sum;
	}
};