#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void empty(int *p, int i)
{
	int n = 0;
	for (n = 0; n < i; n++)
		*p + 4 * n = 0;
	for (n = 0; n < i; n++)
		printf("%d", p + 4 * n);


}
void reverse(int *arr[], int i)
{
	int n = 0;
	int temp = 0;
	for (n = 0; n < i / 2; n++)
	{
		temp = p + 4 * n;
		p + 4 * n = p + 4 * (i - n);
		p + 4 * (i - n) = temp;
	}
}
int main()
{
	int arr[10];
	
	init( *arr,10)
}
void init(*arr, int i)
{
	int n = 0;
	for (n = 0; n < i; n++)
		scanf("%d", p + 4 * n);
	printf("\n");
	for (n = 0; n < i; n++)
		printf("%d", p + 4 * n);

}