#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class team {
	public:
		team(char name[], int sum = 0, int win = 0, int losegame = 0, int get = 0, int loseball = 0, int integral = 0)
		{
			strcpy(_name, name);
			_sumgame = sum;
			_wingame = win;
			_losegame = losegame;
			_getball = get;
			_loseball = loseball;
			_integral = integral;
		}
		void inputscore(team &t2, int first, int second)
		{
			_sumgame++;
			t2._sumgame++;
			if (first > second)
			{
				_wingame++;
				_getball += first;
				_integral += 3;
				t2._losegame++;
				t2._loseball += second;
			}
			else
			{
				if (first == second)
				{
					_integral++;
					t2._integral++;
				}
				else
				{
					t2._wingame++;
					t2._getball += second;
					t2._integral += 3;
					_losegame++;
					_loseball += first;
				}
			}
		}
		void print()
		{
			cout << "�������ƣ�" << _name << endl;
			cout << "�����ܳ�����" << _sumgame << endl;
			cout << "ʤ��������" << _wingame << endl;
			cout << "ս�ܳ�����" << _loseball << endl;
			cout << "������Ŀ:" << _getball << endl;
			cout << "������Ŀ��" << _loseball << endl;
			cout << "������Ŀ��" << _integral << endl;
		}
		int Findindex(team *a, int num, char *name)
		{
			int i = 0;
			for (i = 0; i < num; i++)
			{
				if (!strcmp(a[i]._name, name))
					break;
			}
			if (i>num)
				return -1;
			return i;
		}

		void PrintTeam(team *t, int num)
		{
			int i = 0;
			cout << "���һ����  " << "��    " << "ʤ   " << "ƽ   " << "��   " << "����   " << "ʧ��   " << "����" << endl;
			for (i = 0; i < num; i++)
			{
				sort(t, num);
				int num = t[i]._sumgame - t[i]._wingame - t[i]._losegame;
				cout << t[i]._name << "    " << t[i]._sumgame << "      " << t[i]._wingame << "      " << num << "      " << t[i]._losegame << "      " << t[i]._getball << "      " << t[i]._loseball << "      " << t[i]._integral << endl;
			}
			return;
		}
		bool operator >(team & t)
		{
			if ((*this)._integral > t._integral)
				return true;
			else
				return false;
		}
		void sort(team *t, int num)
		{
			int i = 0;
			int j = 0;
			for (i = 0; i < num; i++)
			{
				for (j = 0; j < num - i - 1; j++)
				{
					if (t[j]>t[j+1])
					{
						team temp(t[j]);
						t[j] = t[j+1];
						t[j+1] = temp;
						//cout << "����λ��" << endl;
					}
				}
			}
		}
   private:
	   char _name[20];
	   int _sumgame;
	   int _wingame;
	   int _losegame;
	   int _getball;
	   int _loseball;
	   int _integral;

};

int main()
{
	team T[3] = { "����͢", "����", "�ձ�" };
	int n = 2;
	while (1)
	{

		char name1[20];
		char name2[20];
		cout << "�������һ�����������" << endl;
		cin >> name1;
		cout << "������ڶ������������" << endl;
		cin >> name2;
		int score1 = 0;
		cout << "�������һ������Ľ�����" << endl;
		cin >> score1;
		int score2 = 0;
		cout << "������ڶ�������Ľ�����" << endl;
		cin >> score2;
		int n1 = 0;
		int n2 = 0;
		int first = 0;
		first = T[0].Findindex(T, 3, name1);
		int second = 0;
		second = T[0].Findindex(T, 3, name2);
		cout << "first team" << first << endl;
		cout << "second team" << second << endl;
		T[first].inputscore(T[second], score1, score2);
		T[0].PrintTeam(T, 3);
		cout << "�Ƿ��˳�  ��1�����˳���0�������)" << endl;
		int h = 1;
		cin >> h;
		if (h)
			break;
	}
	/*for (n1= 0; n1 < 3; n1++)
	{
		if (!strcmp(name2, T[n1].name))
			break;
	}
	for (n2 = 0; n2 < 3; n2++)
	{
		if (!strcmp(name2, T[n2].name))
			break;
	}*/
	
	/*T[n1].print();
	T[n2].print();*/
	//team C("�й�", 5, 3, 2, 3, 2, 10);
	//C.print();
	//team D("�ձ�", 5, 3, 2, 3, 2, 10);
	//D.print();
	system("pause");
	return 0;

}