#define _CRT_SECURE_NO_WARNINGS 1
#include"三子棋.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row;i++)
	{
		//1.打印一行的数据
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]); 
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j<col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void playerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("你的回合，请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		if (board[x - 1][y - 1] == ' ' && x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			printf("玩家走:(%d,%d)\n", x, y);
			board[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("坐标非法,请重新输入\n");
		}
	}
}
void computerMove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			printf("电脑走:(%d,%d)\n", x+1, y+1);
			board[x][y] = '#';
			break;
		}
	}
}

char Iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int x = 0;
	int y = 0;
	for (i = 0; i < row; i++)
	{
		//判断横三行是否相同
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
		//判断竖三列是否相同
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}
	//判断棋盘有没有满
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
				return 'j';//没满，继续
		}
	}
	return 'p';//满了，平局
}