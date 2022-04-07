#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int &x, int &y)//交换函数
{
	int tmp = x;
	x = y;
	y = tmp;
}

void bubble_sort(int arr[], int sz)//冒泡排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)//十个元素需要9趟冒泡排序
	{
		int tag = 1;//假设本趟排序已经有序
		for (j = 0; j<sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				tag = 0;//本趟进行交换，无序
			}		}
		if (tag == 1)//本趟未进行交换，排序已经完成
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
	bubble_sort(arr,sz);//进行冒泡排序
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//打印数组
	}
	return 0;
}