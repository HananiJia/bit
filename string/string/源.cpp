#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>

int StrToInt(string str) {
	int i = 0;
	int lenth = str.size();
	int flag = 0;
	int num = 0;
	int flag1 = 0;//判断正负
	while (str[i] == ' ')
		i++;
	if (str[i] == '-'||str[i]=='+')
		flag = 1;
	
	if ((str[i] >= '0' && str[i] <='9')||flag==1)
	{
		if (str[i] == '-')
			flag1 = 1;//负数
		if (flag == 1)
			i = 1;
		while (str[i]>='0' && str[i] <= '9')
		{
			
			num = num * 10 + str[i]-'0';
			i++;
		}
		if (i == lenth)
		{

			if (flag1== 1)
				return -num;
			else
				return num;
		}
		else
			return 0;	
	}
	else
	{
		return 0;
	}
}

void replaceSpace(char *str, int length) {
	int i = 0;
	int n = length;
	int size = 0;
	while (n)
	{
		if (str[i] == ' ')
		{
			str[i] = '%';
			size = length;
			while (size > i)
			{
				str[size + 2] = str[size];
				size--;
			}
			str[i + 1] = '2';
			str[i + 2] = '0';
		}
		i++;
		n--;
	}

}

int FirstNotRepeatingChar(string str) {
	int a[10000] = { 0 };
	int i = 0;
	while (str[i])
	{
		a[str[i]]++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (a[str[i]] == 1)
		{
			return i; 
		}
	}
	return -1;
}