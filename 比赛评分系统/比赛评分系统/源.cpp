#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>  
#include <string>   
#include<sstream>
//#include"ks.h"  
using namespace std;
//ks.h

class score
{
private:
	int p;
	//double read[7];
	//double a[7];
public:
	score(int pp)//���캯��
	{
		p = pp;
	}
	double  min(double a[], int k)//��������������������ȡ�������Сֵ������������Ҫ���������л��
	{
		double temp;
		for (int j = 0; j<k; j++)
		{
			for (int i = 0; i<k - j - 1; i++)//�������������
			{
				if (a[i]>a[i + 1])
				{
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
		return a[0];//�ú������շ���ֵΪ�������Сֵ
	}


	double max(double a[], int k)//��������������������ȡ��������ֵ������������Ҫ���������л��
	{
		double temp;
		for (int j = 0; j<k; j++)//�������������
		{
			for (int i = 0; i<k - j - 1; i++)
			{
				if (a[i]>a[i + 1])
				{
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
		return a[k - 1];//�ú������շ���ֵΪ��������ֵ
	}




	double  sum(double a[], int k)//�����������������������������Ԫ�صĺ�
	{
		int i;
		double sum = 0;
		if (k<9)//������Ĳ�����k��ֵС��9��ȥ��һ�����һ�����
		{
			for (i = 1; i<k - 1; i++)
			{
				sum = sum + a[i];
			}





		}
		else//������Ĳ�����k��ֵ����9��ȥ����������������
		{
			for (i = 2; i<k - 2; i++)
			{
				sum = sum + a[i];
			}





		}





		return sum;//�ú�������һ��ֵΪ�����������ֵĺ�


	}
	double  aver(double a[], int k)//��������������������������ƽ��ֵ
	{
		double sum = 0;
		double aver = 0;
		if (k<9)//������ĿС��9ȥ��һ�����һ�����
		{
			for (int i = 1; i<k - 1; i++)
			{
				sum = sum + a[i];
			}


			aver = sum / (k - 2);


		}
		else//������Ŀ����9ȥ����������������
		{
			for (int i = 2; i<k - 2; i++)
			{
				sum = sum + a[i];
			}


			aver = sum / (k - 4);






		}


		return aver;//�ú������շ���ֵΪ�������ƽ��ֵ




	}
};
int  main()
{
	score play(10);//��score�ඨ��һ������
	double read[10];//����һ��double���������ڶ�ȡ�ļ��е�ѡ�ֳɼ�
	double a[10];//����һ��double���������ڴ洢�ļ��е�ѡ�ֳɼ�
	double num;//����һ��double���ʹ洢ѡ�ֵı��
	string str;//����һ��string�ַ����洢�ļ���ѡ�ֵ�����
	double pp[10];
	double temp1;
	double qq[10];
	int q = 1;
	int w;
	char s[10];
	double ss[10];
	int u;
	int g;
	int k = 0;//f����һ��k���ڼ�����еĸ���
	char store[1000];//����һ��store�ַ������ڴ�Ŵ��ļ��ж�ȡ����������
	cout << "--------------------------------------------------------------" << endl;
	cout << "                                                              " << endl;
	cout << "1.��ȡ�������ǰ�ļ��ɼ�                                      " << endl;
	cout << "2.�ٴ�����˶�Ա����ɼ�                                      " << endl;
	cout << "                                                              " << endl;
	cout << "--------------------------------------------------------------" << endl;
	cin >> w;
	if (w == 1)
	{
		cout << "�������ȡѡ�ֳɼ�����" << endl;
		cin >> g;
		cout << "���" << "     " << "����" << "             " << "��߷�" << "     " << "��ͷ�" << "       " << "�ܷ�" << "           " << "ƽ����" << endl;


		ifstream in("f1.txt");//�Զ�ȡ����ʽ���ļ�f1
		ofstream out("f2.txt");//��д�����ʽ���ļ�f2
		out << "���" << "     " << "����" << "             " << "��߷�" << "     " << "��ͷ�" << "       " << "�ܷ�" << "           " << "ƽ����" << endl;//���ļ��������仰
		int line;
		for (line = 1; line < g + 1; line++)//���ڽ��ļ����ж�ȡ
		{


			in.seekg(0, ios::beg);


			for (int i = 0; i < line; i++)
			{
				in.getline(store, sizeof(store));//��ȡ�ļ��еĵ�line��
			}


			std::istringstream iss(store);//����ȡ�ķ����ڴ�ռ�


			iss >> num;//���ļ��е����ݱ�Ž�������ת�������뵽int�͵�num��
			iss >> str;//���ļ��е��������������ַ���str��
			cout << num << "       ";
			cout << str << "        ";
			int i = 0;//�����ϱ�������i����i�Ѿ�����һ��ֵ������Ҫ��i���±��0
			k = 0;
			while (iss >> read[i])//���ļ��е�ѡ�ֳɼ����ж�ȡ���Ҵ���read������
			{
				a[i] = read[i];//Ϊ��������ݽ��м��㽫����ȡ���������¸��Ƹ�a����
				//cout << a[i] << "   ";
				i++;
				k++;//ÿ�ζ�ȡ����k�������1�Ӷ���¼�ɼ������Ӷ��õ����е���


			}


			cout << "    ";
			double max = play.max(a, k);//�ö���ȥ�������еĺ���max�Ӷ��õ���������ֵ��������ֵ��double������max
			double min = play.min(a, k);//�ö���ȥ�������еĺ���min�Ӷ��õ��������Сֵ��������ֵ��double������min
			double aver = play.aver(a, k);//�ö���ȥ�������еĺ���aver�Ӷ��õ������ƽ������������ֵ��aver
			double sum = play.sum(a, k);//�ö���ȥ�������еĺ���sum�Ӷ��ĵú����ķ���ֵȻ��ֵ��sum
			cout << max << "       " << min << "            " << sum << "            " << aver << endl;
			out << num << "       ";//���ļ�������ѡ�ֱ��
			out << str << "        ";//���ļ�������ѡ������
			out << max << "       " << min << "            " << sum << "            " << aver << endl;//���ļ�������ѡ�ֵ÷����ֵ��Сֵ�ܺ��Լ�ƽ��ֵ
			pp[line] = play.sum(a, k);//��һ��double�����¼�����˵ĳɼ�
			qq[line] = play.aver(a, k);//��һ�������¼�����˵�ƽ���ɼ�


		}


		for (int m = 0; m < g; m++)//�ɼ��������������
		{
			for (int n = 0; n<g - m - 1; n++)
			{
				if (pp[n]>pp[n + 1])
				{
					temp1 = pp[n];
					pp[n] = pp[n + 1];
					pp[n + 1] = temp1;
				}
			}
		}

		for (int c = 1; c < g + 1; c++)//��������ܳɼ���ͬ�Ƚ�����ƽ���ֽ����ж�
		{
			for (int d = c + 1; d<g + 1; d++)
			if (pp[c] == pp[d])
			{
				cout << "��" << c << "���͵�" << d << "���ܳɼ���ͬ�Ƚ�ƽ����" << endl;
				if (qq[c]>qq[d])
					cout << "���" << pp[c] << "���������θ��ڻ��" << pp[d] << "������" << endl;
				else
					cout << "���" << pp[c] << "���������θ��ڻ��" << pp[d] << "������" << endl;
			}


		}
		for (q = 1; q < g + 1; q++)//��ѭ������������ܳɼ��Լ�����
		{
			cout << "��" << q << "���ĳɼ�Ϊ" << pp[q] << endl;
			out << "��" << q << "���ĳɼ�Ϊ" << pp[q] << endl;
		}
		in.close();//�رն�ȡ���ļ�f1
		out.close();//�رն�ȡ���ļ�f2
	}
	if (w == 2)
	{

		cout << "�����������ӵ�ѡ������" << endl;
		cin >> s;
		cout << "����������ѡ�ֵĳɼ�" << endl;
		for (u = 0; u < 7; u++)
		{
			cin >> ss[u];
		}


		ifstream in;
		ofstream out;
		out.open("f1.txt", ios::app);
		out << "6" << " ";
		out << s << "  ";
		for (u = 0; u < 7; u++)
		{

			out << ss[u] << " ";
		}
		cout << "�Ƿ���㵱ǰ�����˶�Ա�ɼ�";
		cout << "���밴3" << endl;
		cout << "�������˳�" << endl;
		cin >> w;
		if (w == 3)
		{
			cout << "�������ȡѡ�ֳɼ�����" << endl;
			cin >> g;
			cout << "���" << "     " << "����" << "             " << "��߷�" << "     " << "��ͷ�" << "       " << "�ܷ�" << "           " << "ƽ����" << endl;


			in.open("f1.txt");//�Զ�ȡ����ʽ���ļ�f1
			out.open("f2.txt");//��д�����ʽ���ļ�f2
			out << "���" << "     " << "����" << "             " << "��߷�" << "     " << "��ͷ�" << "       " << "�ܷ�" << "           " << "ƽ����" << endl;//���ļ��������仰
			int line;
			for (line = 1; line < g + 1; line++)//���ڽ��ļ����ж�ȡ
			{


				in.seekg(0, ios::beg);


				for (int i = 0; i < line; i++)
				{
					in.getline(store, sizeof(store));//��ȡ�ļ��еĵ�line��
				}


				std::istringstream iss(store);//����ȡ�ķ����ڴ�ռ�


				iss >> num;//���ļ��е����ݱ�Ž�������ת�������뵽int�͵�num��
				iss >> str;//���ļ��е��������������ַ���str��
				cout << num << "       ";
				cout << str << "        ";
				int i = 0;//�����ϱ�������i����i�Ѿ�����һ��ֵ������Ҫ��i���±��0
				k = 0;
				while (iss >> read[i])//���ļ��е�ѡ�ֳɼ����ж�ȡ���Ҵ���read������
				{
					a[i] = read[i];//Ϊ��������ݽ��м��㽫����ȡ���������¸��Ƹ�a����
					//cout << a[i] << "   ";
					i++;
					k++;//ÿ�ζ�ȡ����k�������1�Ӷ���¼�ɼ������Ӷ��õ����е���


				}


				cout << "    ";
				double max = play.max(a, k);//�ö���ȥ�������еĺ���max�Ӷ��õ���������ֵ��������ֵ��double������max
				double min = play.min(a, k);//�ö���ȥ�������еĺ���min�Ӷ��õ��������Сֵ��������ֵ��double������min
				double aver = play.aver(a, k);//�ö���ȥ�������еĺ���aver�Ӷ��õ������ƽ������������ֵ��aver
				double sum = play.sum(a, k);//�ö���ȥ�������еĺ���sum�Ӷ��ĵú����ķ���ֵȻ��ֵ��sum
				cout << max << "       " << min << "            " << sum << "            " << aver << endl;
				out << num << "       ";//���ļ�������ѡ�ֱ��
				out << str << "        ";//���ļ�������ѡ������
				out << max << "       " << min << "            " << sum << "            " << aver << endl;//���ļ�������ѡ�ֵ÷����ֵ��Сֵ�ܺ��Լ�ƽ��ֵ
				pp[line] = play.sum(a, k);//��һ��double�����¼�����˵ĳɼ�
				qq[line] = play.aver(a, k);//��һ�������¼�����˵�ƽ���ɼ�


			}


			for (int m = 0; m < g; m++)//�ɼ��������������
			{
				for (int n = 0; n<g - m - 1; n++)
				{
					if (pp[n]>pp[n + 1])
					{
						temp1 = pp[n];
						pp[n] = pp[n + 1];
						pp[n + 1] = temp1;
					}
				}
			}

			for (int c = 1; c < g + 1; c++)//��������ܳɼ���ͬ�Ƚ�����ƽ���ֽ����ж�
			{
				for (int d = c + 1; d<g + 1; d++)
				if (pp[c] == pp[d])
				{
					cout << "��" << c << "���͵�" << d << "���ܳɼ���ͬ�Ƚ�ƽ����" << endl;
					if (qq[c]>qq[d])
						cout << "���" << pp[c] << "���������θ��ڻ��" << pp[d] << "������" << endl;
					else
						cout << "���" << pp[c] << "���������θ��ڻ��" << pp[d] << "������" << endl;
				}


			}
			for (q = 1; q < g + 1; q++)//��ѭ������������ܳɼ��Լ�����
			{
				cout << "��" << q << "���ĳɼ�Ϊ" << pp[q] << endl;
				out << "��" << q << "���ĳɼ�Ϊ" << pp[q] << endl;
			}
			in.close();//�رն�ȡ���ļ�f1
			out.close();//�رն�ȡ���ļ�f2
		}
	}
}

	