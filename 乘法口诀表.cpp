#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 9
void print_table(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	print_table(MAX);
	return 0;
}