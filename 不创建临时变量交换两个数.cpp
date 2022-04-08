#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//加减法(可能会溢出)
void exchange1(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
//异或法
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