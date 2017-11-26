#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void init( int arr[] ,int i)
{
	int n = 0;
	for (n = 0; n < i; n++)
	{
		printf("请输入第%d个数据\n",n+1);
		scanf("%d", &arr[n]);
	}
	printf("\n");
	for (n = 0; n < i; n++)
		printf("%d\n", arr[n]);

}
void empty(int arr[], int i)
{
	int n = 0;
	for (n = 0; n < i; n++)
		arr[n]= 0;
	printf("数组清空完成,清空后数据为\n");
	for (n = 0; n < i; n++)
		printf("%d\n",arr[n]);


}
void reverse(int arr[], int i)
{
	int n = 0;
	int temp = 0;
	for (n = 0; n < (i-1) / 2; n++)
	{
		temp =arr[n];
		arr[n] = arr[i-n-1];
		arr[i-n-1] = temp;
	}
	printf("数组交换完成，交换后为\n");
	for (n = 0; n < i; n++)
		printf("%d\n", arr[n]);
}
int main()
{
	int arr[11];
	
	empty(arr, 11);
	init(arr, 11);
	reverse(arr, 11);
	system("pause");
}
