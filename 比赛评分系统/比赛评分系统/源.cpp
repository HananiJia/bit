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
	score(int pp)//构造函数
	{
		p = pp;
	}
	double  min(double a[], int k)//定义两个参数，求所读取数组的最小值，两个参数需要从主函数中获得
	{
		double temp;
		for (int j = 0; j<k; j++)
		{
			for (int i = 0; i<k - j - 1; i++)//对数组进行排序
			{
				if (a[i]>a[i + 1])
				{
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
				}
			}
		}
		return a[0];//该函数最终返回值为数组的最小值
	}


	double max(double a[], int k)//定义两个参数，求所读取数组的最大值，两个参数需要从主函数中获得
	{
		double temp;
		for (int j = 0; j<k; j++)//对数组进行排序
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
		return a[k - 1];//该函数最终返回值为数组的最大值
	}




	double  sum(double a[], int k)//定义两个参数，用于求该数组所有元素的和
	{
		int i;
		double sum = 0;
		if (k<9)//如果给的参数中k的值小于9则去掉一个最高一个最低
		{
			for (i = 1; i<k - 1; i++)
			{
				sum = sum + a[i];
			}





		}
		else//如果给的参数中k的值大于9则去掉两个最高两个最低
		{
			for (i = 2; i<k - 2; i++)
			{
				sum = sum + a[i];
			}





		}





		return sum;//该函数返回一个值为数组所有数字的和


	}
	double  aver(double a[], int k)//定义两个参数，用于求该数组的平均值
	{
		double sum = 0;
		double aver = 0;
		if (k<9)//裁判数目小于9去掉一个最高一个最低
		{
			for (int i = 1; i<k - 1; i++)
			{
				sum = sum + a[i];
			}


			aver = sum / (k - 2);


		}
		else//裁判数目大于9去掉两个最高两个最低
		{
			for (int i = 2; i<k - 2; i++)
			{
				sum = sum + a[i];
			}


			aver = sum / (k - 4);






		}


		return aver;//该函数最终返回值为该数组的平均值




	}
};
int  main()
{
	score play(10);//给score类定义一个对象
	double read[10];//定义一个double型数组用于读取文件中的选手成绩
	double a[10];//定义一个double型数组用于存储文件中的选手成绩
	double num;//定义一个double类型存储选手的编号
	string str;//定义一个string字符串存储文件中选手的名字
	double pp[10];
	double temp1;
	double qq[10];
	int q = 1;
	int w;
	char s[10];
	double ss[10];
	int u;
	int g;
	int k = 0;//f定义一个k用于计算裁判的个数
	char store[1000];//定义一个store字符串用于存放从文件中读取的所有内容
	cout << "--------------------------------------------------------------" << endl;
	cout << "                                                              " << endl;
	cout << "1.读取并输出当前文件成绩                                      " << endl;
	cout << "2.再次添加运动员及其成绩                                      " << endl;
	cout << "                                                              " << endl;
	cout << "--------------------------------------------------------------" << endl;
	cin >> w;
	if (w == 1)
	{
		cout << "请输入读取选手成绩个数" << endl;
		cin >> g;
		cout << "编号" << "     " << "姓名" << "             " << "最高分" << "     " << "最低分" << "       " << "总分" << "           " << "平均分" << endl;


		ifstream in("f1.txt");//以读取的形式打开文件f1
		ofstream out("f2.txt");//以写入的形式打开文件f2
		out << "编号" << "     " << "姓名" << "             " << "最高分" << "     " << "最低分" << "       " << "总分" << "           " << "平均分" << endl;//向文件中输出这句话
		int line;
		for (line = 1; line < g + 1; line++)//用于将文件分行读取
		{


			in.seekg(0, ios::beg);


			for (int i = 0; i < line; i++)
			{
				in.getline(store, sizeof(store));//读取文件中的第line行
			}


			std::istringstream iss(store);//给读取的分配内存空间


			iss >> num;//将文件中的数据编号进行类型转换并存入到int型的num中
			iss >> str;//将文件中的数据姓名存入字符串str中
			cout << num << "       ";
			cout << str << "        ";
			int i = 0;//由于上边运用了i并且i已经有了一个值这里需要将i重新变回0
			k = 0;
			while (iss >> read[i])//对文件中的选手成绩进行读取并且存入read数组中
			{
				a[i] = read[i];//为方便对数据进行计算将所读取的数组重新复制给a数组
				//cout << a[i] << "   ";
				i++;
				k++;//每次读取数据k都将会加1从而记录成绩个数从而得到裁判的数


			}


			cout << "    ";
			double max = play.max(a, k);//用对象去调用类中的函数max从而得到数组的最大值并将它赋值给double型数据max
			double min = play.min(a, k);//用对象去调用类中的函数min从而得到数组的最小值并将它赋值给double型数据min
			double aver = play.aver(a, k);//用对象去调用类中的函数aver从而得到数组的平均数并将它赋值给aver
			double sum = play.sum(a, k);//用对象去调用类中的函数sum从而的得函数的返回值然后赋值给sum
			cout << max << "       " << min << "            " << sum << "            " << aver << endl;
			out << num << "       ";//向文件中输入选手编号
			out << str << "        ";//向文件中输入选手姓名
			out << max << "       " << min << "            " << sum << "            " << aver << endl;//向文件中输入选手得分最大值最小值总和以及平均值
			pp[line] = play.sum(a, k);//用一个double数组记录所有人的成绩
			qq[line] = play.aver(a, k);//用一个数组记录所有人的平均成绩


		}


		for (int m = 0; m < g; m++)//成绩对数组进行排序
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

		for (int c = 1; c < g + 1; c++)//如果两人总成绩相同比较两人平均分进行判断
		{
			for (int d = c + 1; d<g + 1; d++)
			if (pp[c] == pp[d])
			{
				cout << "第" << c << "名和第" << d << "名总成绩相同比较平均分" << endl;
				if (qq[c]>qq[d])
					cout << "获得" << pp[c] << "分数的名次高于获得" << pp[d] << "分数的" << endl;
				else
					cout << "获得" << pp[c] << "分数的名次高于获得" << pp[d] << "分数的" << endl;
			}


		}
		for (q = 1; q < g + 1; q++)//用循环输出所有人总成绩以及名次
		{
			cout << "第" << q << "名的成绩为" << pp[q] << endl;
			out << "第" << q << "名的成绩为" << pp[q] << endl;
		}
		in.close();//关闭读取的文件f1
		out.close();//关闭读取的文件f2
	}
	if (w == 2)
	{

		cout << "请输入新增加的选手姓名" << endl;
		cin >> s;
		cout << "请依次输入选手的成绩" << endl;
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
		cout << "是否计算当前所有运动员成绩";
		cout << "是请按3" << endl;
		cout << "否则请退出" << endl;
		cin >> w;
		if (w == 3)
		{
			cout << "请输入读取选手成绩个数" << endl;
			cin >> g;
			cout << "编号" << "     " << "姓名" << "             " << "最高分" << "     " << "最低分" << "       " << "总分" << "           " << "平均分" << endl;


			in.open("f1.txt");//以读取的形式打开文件f1
			out.open("f2.txt");//以写入的形式打开文件f2
			out << "编号" << "     " << "姓名" << "             " << "最高分" << "     " << "最低分" << "       " << "总分" << "           " << "平均分" << endl;//向文件中输出这句话
			int line;
			for (line = 1; line < g + 1; line++)//用于将文件分行读取
			{


				in.seekg(0, ios::beg);


				for (int i = 0; i < line; i++)
				{
					in.getline(store, sizeof(store));//读取文件中的第line行
				}


				std::istringstream iss(store);//给读取的分配内存空间


				iss >> num;//将文件中的数据编号进行类型转换并存入到int型的num中
				iss >> str;//将文件中的数据姓名存入字符串str中
				cout << num << "       ";
				cout << str << "        ";
				int i = 0;//由于上边运用了i并且i已经有了一个值这里需要将i重新变回0
				k = 0;
				while (iss >> read[i])//对文件中的选手成绩进行读取并且存入read数组中
				{
					a[i] = read[i];//为方便对数据进行计算将所读取的数组重新复制给a数组
					//cout << a[i] << "   ";
					i++;
					k++;//每次读取数据k都将会加1从而记录成绩个数从而得到裁判的数


				}


				cout << "    ";
				double max = play.max(a, k);//用对象去调用类中的函数max从而得到数组的最大值并将它赋值给double型数据max
				double min = play.min(a, k);//用对象去调用类中的函数min从而得到数组的最小值并将它赋值给double型数据min
				double aver = play.aver(a, k);//用对象去调用类中的函数aver从而得到数组的平均数并将它赋值给aver
				double sum = play.sum(a, k);//用对象去调用类中的函数sum从而的得函数的返回值然后赋值给sum
				cout << max << "       " << min << "            " << sum << "            " << aver << endl;
				out << num << "       ";//向文件中输入选手编号
				out << str << "        ";//向文件中输入选手姓名
				out << max << "       " << min << "            " << sum << "            " << aver << endl;//向文件中输入选手得分最大值最小值总和以及平均值
				pp[line] = play.sum(a, k);//用一个double数组记录所有人的成绩
				qq[line] = play.aver(a, k);//用一个数组记录所有人的平均成绩


			}


			for (int m = 0; m < g; m++)//成绩对数组进行排序
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

			for (int c = 1; c < g + 1; c++)//如果两人总成绩相同比较两人平均分进行判断
			{
				for (int d = c + 1; d<g + 1; d++)
				if (pp[c] == pp[d])
				{
					cout << "第" << c << "名和第" << d << "名总成绩相同比较平均分" << endl;
					if (qq[c]>qq[d])
						cout << "获得" << pp[c] << "分数的名次高于获得" << pp[d] << "分数的" << endl;
					else
						cout << "获得" << pp[c] << "分数的名次高于获得" << pp[d] << "分数的" << endl;
				}


			}
			for (q = 1; q < g + 1; q++)//用循环输出所有人总成绩以及名次
			{
				cout << "第" << q << "名的成绩为" << pp[q] << endl;
				out << "第" << q << "名的成绩为" << pp[q] << endl;
			}
			in.close();//关闭读取的文件f1
			out.close();//关闭读取的文件f2
		}
	}
}

	