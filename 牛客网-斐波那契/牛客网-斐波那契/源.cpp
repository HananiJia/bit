#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int Fibonacci(int n) {
	if (n <= 0)
		return 0;
	int first = 1;
	int second = 1;
	if (n == 1 || n == 2)
		return 1;
	int pre1 = first;
	int pre2 = second;
	int num = 0;
	int sum = 0;
	int count = n;
	while (count>=3)
	{
		sum = pre1 + pre2;
		pre1 = pre2;
		pre2 = sum;
		num = sum;
		count--;

	}
	return num;
}
int main()
{
	int cout1 = 0;
	cout1=Fibonacci(3);
	cout << "3:" << cout1 << endl;
	cout1 = Fibonacci(4);
	cout << "4:" << cout1 << endl;
	system("pause");
	return 0;

}
