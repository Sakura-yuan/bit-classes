#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�Ӽ���(���ܻ����)
void exchange1(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
//���
void exchange2(int &a, int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
int main()
{
	int a = 3;
	int b = 5;
	exchange2(a, b);
	printf("a=%d b=%d\n", a, b);
	return 0;
}