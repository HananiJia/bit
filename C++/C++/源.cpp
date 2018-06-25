#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;
class Data
{
public:
	Data()
	{}
	Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void print()
	{
		cout << _year << endl;
	}
private:
	int _year;
	int _month;
	int _day;

};
int main()
{
	Data d1;
	Data d2(1997, 10, 24);
	Data d3;

}