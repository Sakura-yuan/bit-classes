#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int statics1(int num)
{
	int count = 0;//计数多少个1
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if ((num >> i) & 1 == 1)//按位与1，如果结果是1计数器加一，然后右移，循环32次
		{
			count++;
		}
	}
	return count;
}
int statics2(int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);//不断缩小的过程，每次按位与的结果都把num中 1的位 从右到左 依次置为0
		count++;
	}
	return count;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("count = %d\n", statics2(num));
	return 0;
}