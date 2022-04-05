#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int count = 0;
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_leap_year(year) == 1)
		{
			printf("%d ", year);
			count++;
		}
	}
	printf("\ncount=%d ", count);
	return 0;
}