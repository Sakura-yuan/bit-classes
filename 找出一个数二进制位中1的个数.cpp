#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int statics1(int num)
{
	int count = 0;//�������ٸ�1
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((num >> i) & 1 == 1)//��λ��1����������1��������һ��Ȼ�����ƣ�ѭ��32��
		{
			count++;
		}
	}
	return count;
}
int statics2(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);//������С�Ĺ��̣�ÿ�ΰ�λ��Ľ������num�� 1��λ ���ҵ��� ������Ϊ0
		count++;
	}
	return count;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("count = %d\n", statics2(num));
	return 0;
}