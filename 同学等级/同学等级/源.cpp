#include<iostream>
using namespace std;
int main()
{
	int m;
	int n=0;
	cout << "请输入同学的成绩" << endl;
	cin >> m;
	n = m / 10;
	
	switch (n)
	{

	case 1:cout << "D"; break;
	case 2:cout << "D"; break;
	case 3:cout << "D"; break;
	case 4:cout << "D"; break;
	case 5:cout << "D"; break;
	case 6:cout << "C"; break;
	case 7:cout << "C"; break;
	case 8:cout << "B"; break;
	case 9:cout << "A"; break;
	case 10:cout << "A"; break;

	default:cout << "error\n"  ;

	}
}