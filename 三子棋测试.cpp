#define _CRT_SECURE_NO_WARNINGS 1
#include"������.h"

void menu()
{
	printf("******************\n");
	printf("******1.play******\n");
	printf("******0.exit******\n");
	printf("******************\n");
}
//��Ϸ�������㷨ʵ��
void game()
{
	char ret = 0;
	int i = 0;
	int j = 0;
	//����-����߳���������Ϣ
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		playerMove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);
		if (ret != 'j')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	if (ret == 'p')
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}