#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int get_diff_bit(int a, int b)
{
	//011111001111   1999
	//100011111011   2299
	//��ͬλ����Ϊ7
	int c = a^b;//�����ͬΪ0����Ϊ1
	int count = 0;
	while (c)//����1�ĸ���
	{
		c = c&(c - 1);
		count++;
	}
	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d%d", &a, &b);
	printf("count = %d\n", get_diff_bit(a, b));
	return 0;
}