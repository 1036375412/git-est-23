#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void exc(int arr1[], int arr2[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr1[10] = { 1,3,5,7,9 };
	int arr2[10] = { 2,4,6,8,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	exc(arr1, arr2, sz);
	print(arr1, sz);
	print(arr2, sz);
	return 0;
}