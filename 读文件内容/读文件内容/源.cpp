#include <iostream>
#include <fstream>  
#include <string>   
#include<sstream>
#include"ks.h"  
using namespace std;
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
	int i;
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

			for (i = 0; i < line; i++)
			{
				in.getline(store, sizeof(store));//读取文件中的第line行
			}

			std::istringstream iss(store);//给读取的分配内存空间

			iss >> num;//将文件中的数据编号进行类型转换并存入到int型的num中
			iss >> str;//将文件中的数据姓名存入字符串str中
			cout << num << "       ";
			cout << str << "        ";
			i = 0;//由于上边运用了i并且i已经有了一个值这里需要将i重新变回0
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

				for (i = 0; i < line; i++)
				{
					in.getline(store, sizeof(store));//读取文件中的第line行
				}

				std::istringstream iss(store);//给读取的分配内存空间

				iss >> num;//将文件中的数据编号进行类型转换并存入到int型的num中
				iss >> str;//将文件中的数据姓名存入字符串str中
				cout << num << "       ";
				cout << str << "        ";
				i = 0;//由于上边运用了i并且i已经有了一个值这里需要将i重新变回0
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
	system("pause");
}