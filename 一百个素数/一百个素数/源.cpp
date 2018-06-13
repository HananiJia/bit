#include<iostream>
using namespace std;
void main()
{
	int m, i;
	double k;
	int n=0;
	for (m = 2; m <= 10000; m = m + 1)
	{
		k = sqrt(m);
		for (i = 2; i <= k; i++)
		

			if (m%i == 0) break;
			if (i > k)
			{

				n++;
				cout << m << endl;
			}
		
		if (n == 100)break;
	}
	
	system("pause");
}