#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		int i = 0;
//		int length = input.size();
//		for (i = 0; i < length; i++)
//		{
//			for (int j = 0; j < length - i - 1; j++)
//			{
//				if (input[j]>input[j + 1])
//				{
//					int temp = input[j];
//					input[j] = input[j+1];
//					input[j + 1] = temp;
//				}
//			}
//		}
//		vector<int> array;
//		for (i = 0; i <= k; i++)
//		{
//			array.push_back(input[i]);
//		}
//		return array;
//
//	}
//};
//
//int main()
//{
//	Solution A;
//	vector<int> ary;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		ary.push_back(i);
//	}
//	vector<int> arr;
//	arr=A.GetLeastNumbers_Solution(ary, 4);
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d", arr[i]);
//
//	}
//	
//	system("pause");
//	return 0;
//}

//调用库函数
//class Solution {
//public:
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> array;
//		int length = input.size();
//		if (k > length||k<=0)
//		{
//			return array;
//		}
//		sort(input.begin(), input.end());
//		
//		for (int i = 0; i < k; i++)
//		{
//			array.push_back(input[i]);
//		}
//		return array;
//
//	}
//};

//运用堆排序

//class Solution {
//public:
//	void Adjustdown(vector<int> a, int length, int root)
//	{
//		int parent = root;
//		int child = parent * 2 + 1;
//		while (child<length)
//		{
//
//			if ((child + 1 < length) && a[child + 1] > a[child])
//			{
//				child++;
//			}
//			if (a[child] < a[parent])
//			{
//				int temp = a[child];
//				a[child] = a[parent];
//				a[parent] = temp;
//				parent = child;
//				child = parent * 2 + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> array;
//		int length = input.size();
//		if (k > length || k <= 0)
//		{
//			return array;
//		}
//		int i = (k - 2) / 2;
//		for (; i >= 0; i--)
//		{
//			Adjustdown(input, length, i);
//		}
//		for (i = k; i < length; i++)
//		{
//			if (input[i]<input[0])
//			{
//				int temp = input[i];
//				input[i] = input[0];
//				input[0] = temp;
//				Adjustdown(input, k, 0);
//			}
//		}
//		for (i = 0; i <k; i++)
//		{
//			array.push_back(input[i]);
//		}
//
//		return array;
//	}
//};

//class Solution {
//public:
//
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//
//		vector<int> result;
//		if (input.size() == 0 || k == 0 || k>input.size()){
//			return result;
//		}
//		for (int i = input.size() / 2 - 1; i >= 0; i--){//初始化堆
//
//			adjustHeap(input, i, k);
//		}
//		int i = k;
//		while (i<input.size()){
//
//			if (input[0]>input[i]){
//				int temp = input[i];
//				input[i] = input[0];
//				input[0] = temp;
//				adjustHeap(input, 0, k);
//				i = k;
//			}
//			else {
//				i++;
//			}
//
//
//
//		}
//
//		for (int i = 0; i<k; i++){
//
//			result.push_back(input[i]);
//		}
//
//		return result;
//
//
//
//	}
//
//	void adjustHeap(vector<int>&input, int i, int length){//堆调整
//
//		int child = i * 2 + 1;
//		if (child<length){
//
//			if (child + 1<length&&input[child + 1]>input[child]){
//				child = child + 1;
//			}
//			if (input[child]>input[i]){
//				int temp = input[i];
//				input[i] = input[child];
//				input[child] = temp;
//				adjustHeap(input, child, length);
//			}
//
//		}
//
//	}
//	void heapSort(vector<int>&input, int length){//堆排序
//		for (int i = length / 2 - 1; i >= 0; i--){//初始化堆
//
//			adjustHeap(input, i, length);
//		}
//
//		for (int i = length - 1; i>0; i--){
//			int temp = input[i];
//			input[i] = input[0];
//			input[0] = temp;
//			adjustHeap(input, 0, i);
//
//		}
//
//	}
//
//};


//	void AdjustDown(vector<int> a, int n, int root)
//
//	{
//		int child = root * 2 + 1;
//
//		int parent = root;
//
//		while (child < n)
//
//		{
//
//			if ((child + 1<n) && (a[child + 1] < a[child]))
//
//				child++;
//
//			if (a[parent]>a[child])
//
//			{
//
//				int temp = a[child];
//
//				a[child] = a[parent];
//
//				a[parent] = temp;;
//
//				parent = child;
//
//				child = parent * 2 + 1;
//
//			}
//
//			else
//
//				break;
//		}
//
//	}
//
//	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//		vector<int> array;
//		int num = input.size();
//		if (k > num || k <= 0)
//		{
//			return array;
//		}
//		int i = (k - 2) / 2;
//
//		for (; i >= 0; i--)
//
//		{
//
//			AdjustDown(input, k, i);
//
//		}
//
//		for (i = k; i < num; i++)
//
//		{
//
//			if (input[i]>input[0])
//
//			{
//
//				int temp = input[0];
//
//				input[0] = input[i];
//
//				input[i] = temp;
//
//				AdjustDown(input, k, 0);
//
//			}
//		}
//		for (i = 0; i < k; i++)
//		{
//			array.push_back(input[i]);
//		}
//		return array;
//	}
//
//int main()
//{
//	
//	vector<int> ary = { 4, 5, 1, 6, 2, 7, 3, 8 };
//	int i = 0;
//	vector<int> arr;
//	arr=GetLeastNumbers_Solution(ary, 4);
//	for (i = 0; i < 4; i++)
//	{
//		cout << arr[i];
//	}
//	system("pause");
//	return 0;
//}

	void AdjustDown(vector<int> a, int n, int root)

	{

		int child = root * 2 + 1;

		int parent = root;

		while (child < n)

		{

			if ((child + 1 < n) && (a[child + 1] > a[child]))

				child++;

			if (a[parent] < a[child])

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
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)

	{
		int n = input.size();
		int num = n;

		int i = (k - 2) / 2;

		for (; i >= 0; i--)

		{



			AdjustDown(input, k, i);

		}

		for (i = k; i < num; i++)

		{

			if (input[i] < input[0])

			{

				int temp = input[0];

				input[0] = input[i];

				input[i] = temp;

				AdjustDown(input, k, 0);

			}

		}

		
		for (i = 0; i < k; i++)
		{

			printf("%d", input[i]);
		}
		vector <int> a;
		return a;
	}

int main()

{
	
	vector<int> arr = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> a;
	a=GetLeastNumbers_Solution(arr,4);
	system("pause");

	return 0;

}
