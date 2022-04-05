#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <windows.h>

int Fib1(int n)
{
	if (n <= 2)
		return 1;
	else
		return  Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)
{
	int a = 1;
	int b = 1;
	int c;
	if (n <= 2)
		return 1;
	while(n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	SYSTEMTIME sys;
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", Fib1(n));
	printf("%d\n", Fib2(n));
	return 0;
}