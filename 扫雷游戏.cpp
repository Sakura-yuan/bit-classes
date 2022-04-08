#define _CRT_SECURE_NO_WARNINGS 1
#include"扫雷.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	printf("   |");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		if (i < row )
			printf("|");
	}
	printf("\n");
	for (i = 0; i <= row+1; i++)
	{
		if (i <= row)
		{
			printf("---");
			if (i <= row-1)
				printf("|");
		}
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf(" %d |",i);
		//1.打印一行的数据
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row)
		{
			for (j = 0; j <= col; j++)
			{
				printf("---");
				if (j <= col-1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row+1;//1-9
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)//把周围八个元素加起来就是雷的个数
{
	//字符1减字符0就是数字1；因为ASKII码值是挨着的；
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void recursive_demining(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int &win)
{
	int i = 0;
	int j = 0;
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		win++;//没踩到雷，win++
		if (get_mine_count(mine, x, y) == 0)//坐标周围没有雷
		{
			show[x][y] = ' ';
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')
					{
						recursive_demining(mine, show, i, j, win);
					}
				}
			}
		}
		else
		{
			show[x][y] = get_mine_count(mine, x, y) + '0';
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y]=='*')
		{
			//坐标合法
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//不是雷
			{
				//计算x，y坐标周围有几个雷
				recursive_demining(mine, show, x, y, win);//递归扫雷，周围没有雷就递归的在四周扫描，直到围成一圈有雷的格子
				DisplayBoard(show, row, col);
				
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");
		}	    
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
	}
}