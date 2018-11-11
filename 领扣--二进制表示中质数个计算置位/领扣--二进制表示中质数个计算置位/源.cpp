#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		int count = 0;
		for (int i = L; i <= R; i++)
		{
			int bit=CountSetBit(i);
			if (isPrime(bit))
			{
				count++;
			}
		}
		return count;
	}
	bool isPrime(int num)
	{
		if (num == 1)
			return false;
		int i = 0;
		for (i = 2; i <= sqrt(num); i++)
		{
			if ((num % i) == 0)
			{
				return false;
			}
		}
		
		return true;
		
		
	}
	int  CountSetBit(int num)
	{
		int count = 0;
		while (num)
		{
			if ((num & 1) == 1)
			{
				count++;
			}
			num = num >> 1;
		}
		return count;
	}
};

int main()
{
	Solution A;
	int num=A.countPrimeSetBits(10, 15);
	cout << num << endl;
	system("pause");
	return 0;
}
