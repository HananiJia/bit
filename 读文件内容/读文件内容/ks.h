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
