#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	while (i <= 100)
	{
		if (1 == i%2)
			printf("%d\n", i);
		i++;
	}
	return 0;
}
