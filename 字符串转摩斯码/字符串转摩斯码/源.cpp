#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	string temp;
	cout << "请输入想要转换的字符串" << endl;
	cin >> temp;
	int i = 0;
	while (char n = temp[i++])
	{
		cout << str[n - 97];
	}
	system("pause");
	return 0;


}