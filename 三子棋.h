#define ROW 3
#define COL 3
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL], int row, int col);
void playerMove(char board[ROW][COL], int row, int col);
void computerMove(char board[ROW][COL]);
char Iswin(char board[ROW][COL], int row, int col);
//返回*玩家赢
//返回#电脑赢
//返回p平局
//返回j继续
