#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int is_prime(int n)//����������1�����Ƿ���0
{
	int i = 0;
	for (i = 2; i <= sqrt((double)n); i++)//�Գ�2-nƽ����   �������һ��С�ڵ���nƽ����
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
	int count = 0;//����������
	for (i = 101; i <= 200; i += 2)//��ӡ100��200����������
	{
		if (is_prime(i) == 1)
		{
			printf("%d ", i);//��ӡ����
			count++;//������һ
		}
	}
	printf("\ncount=%d\n", count);
	return 0;
}