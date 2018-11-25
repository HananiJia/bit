 #define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>
using namespace std;

int GetAndRemoveLastNum(stack<int>& s)
{
	int num = s.top(); 
	s.pop();
	if (s.empty())
	{
		return num;
	}
	else
	{
		int last = GetAndRemoveLastNum(s);
		s.push(num);
		return last;
	}

}

void reverse(stack<int>& s)
{
	if (s.empty())
		return;
	int num = GetAndRemoveLastNum(s);
	reverse(s);
	s.push(num);

}

int main()
{
	stack<int> a;
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	a.push(5);
	reverse(a);
	cout << a.top() << endl;
	a.pop(); 
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	system("pause");
	return 0;

}