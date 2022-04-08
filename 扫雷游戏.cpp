#define _CRT_SECURE_NO_WARNINGS 1
#include"ɨ��.h"
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
	//��ӡ�к�
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
		//��ӡ�к�
		printf(" %d |",i);
		//1.��ӡһ�е�����
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
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

int get_mine_count(char mine[ROWS][COLS], int x, int y)//����Χ�˸�Ԫ�ؼ����������׵ĸ���
{
	//�ַ�1���ַ�0��������1����ΪASKII��ֵ�ǰ��ŵģ�
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
		win++;//û�ȵ��ף�win++
		if (get_mine_count(mine, x, y) == 0)//������Χû����
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
			//����Ϸ�
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//������
			{
				//����x��y������Χ�м�����
				recursive_demining(mine, show, x, y, win);//�ݹ�ɨ�ף���Χû���׾͵ݹ��������ɨ�裬ֱ��Χ��һȦ���׵ĸ���
				DisplayBoard(show, row, col);
				
			}
		}
		else
		{
			printf("��������Ƿ������������룡\n");
		}	    
	}
	if (win == row*col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ�\n");
	}
}