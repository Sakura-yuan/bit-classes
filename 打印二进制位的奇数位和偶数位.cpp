#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int m)
{
	int i = 0;
	printf("����λ:\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\nż��λ:\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n");
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}