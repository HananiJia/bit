#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void AdjustDown(int *a, int n, int root)
{
	int child = root * 2 + 1;
	int parent = root;
	while (child < n)
	{
		if ((child+1<n)&&(a[child + 1] < a[child]))
			child++;
		if (a[parent]>a[child])
		{
			int temp = a[child];
			a[child] = a[parent];
			a[parent] = temp;;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapTopK(int *a, int n, int k)
{
	int num = n;
	int i= (k - 2) / 2;
	for (; i >= 0; i--)
	{

		AdjustDown(a, k, i);
	}
	for (i = k; i < num; i++)
	{
		if (a[i]>a[0])
		{
			int temp = a[0];
			a[0] = a[i];
			a[i] = temp;
			AdjustDown(a, k, 0);
		}
	}
	for (i = 0; i < k; i++)
	{

		printf("%d\n", a[i]);
	}
}
int main()
{
	int arr[10] = { 1, 23, 43, 45, 65, 76, 78, 98, 90, 123 };
	HeapTopK(arr, 10, 5);
	system("pause");
	return 0;
}