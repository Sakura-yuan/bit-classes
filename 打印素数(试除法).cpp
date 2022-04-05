#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int is_prime(int n)//是素数返回1，不是返回0
{
	int i = 0;
	for (i = 2; i <= sqrt((double)n); i++)//试除2-n平方根   最大公因数一定小于等于n平方根
	{
		if (n%i == 0)
			return 0;
	}
	if (i > sqrt((double)n))
		return 1;
}

int main()
{
	int i = 0;
	int count = 0;//素数的数量
	for (i = 101; i <= 200; i += 2)//打印100到200的所有素数
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);//打印素数
			count++;//数量加一
		}
	}
	printf("\ncount=%d\n", count);
	return 0;
}