#define _CRT_SECURE_NO_WARNINGS 1
#include"三子棋.h"

void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
//游戏的整个算法实现
void game()
{
	char ret = 0;
	int i = 0;
	int j = 0;
	//数组-存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		playerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		//电脑下棋
		computerMove(board);
		Displayboard(board, ROW, COL);
		Iswin(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	if (ret == '#')
	{
		printf("电脑赢\n");
	}
	if (ret == 'p')
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
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
			printf("选择错误，请重新选择：\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}