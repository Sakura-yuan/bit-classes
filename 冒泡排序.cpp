#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void Swap(int &x, int &y)//��������
{
	int tmp = x;
	x = y;
	y = tmp;
}

void bubble_sort(int arr[], int sz)//ð������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)//ʮ��Ԫ����Ҫ9��ð������
	{
		int tag = 1;//���豾�������Ѿ�����
		for (j = 0; j<sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				Swap(arr[j], arr[j + 1]);
				tag = 0;//���˽��н���������
			}		}
		if (tag == 1)//����δ���н����������Ѿ����
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ�ظ���
	bubble_sort(arr,sz);//����ð������
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);//��ӡ����
	}
	return 0;
}