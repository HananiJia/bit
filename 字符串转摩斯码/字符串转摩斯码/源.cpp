#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	string temp;
	cout << "��������Ҫת�����ַ���" << endl;
	cin >> temp;
	int i = 0;
	while (char n = temp[i++])
	{
		cout << str[n - 97];
	}
	system("pause");
	return 0;


}