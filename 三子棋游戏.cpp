#define _CRT_SECURE_NO_WARNINGS 1
#include"������.h"


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
		//1.��ӡһ�е�����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]); 
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
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
		printf("��Ļغϣ�������Ҫ�µ�����:>");
		scanf("%d%d", &x, &y);
		if (board[x - 1][y - 1] == ' ' && x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			printf("�����:(%d,%d)\n", x, y);
			board[x - 1][y - 1] = '*';
			break;
		}
		else
		{
			printf("����Ƿ�,����������\n");
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
			printf("������:(%d,%d)\n", x+1, y+1);
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
		//�жϺ������Ƿ���ͬ
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
		//�ж��������Ƿ���ͬ
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�ж϶Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}
	//�ж�������û����
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (board[x][y] == ' ')
				return 'j';//û��������
		}
	}
	return 'p';//���ˣ�ƽ��
}