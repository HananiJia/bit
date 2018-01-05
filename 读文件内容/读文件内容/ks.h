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
