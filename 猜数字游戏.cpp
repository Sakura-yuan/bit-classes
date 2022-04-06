#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("***********************************\n");
	printf("*****    1.play     0.exit    *****\n");
	printf("***********************************\n");
}

void game()
{
	int random = 0;
	int guess = 0;
	random = rand()%100;//1.生产一个1-100的随机数
	//2.猜数字
	while (1)
	{
		printf("请猜数字\n");
		scanf("%d", &guess);
		if (guess>random)
			printf("猜大了\n");
		else if (guess < random)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
	
	
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}