#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("***********************\n");
	printf("******  1. game  ******\n");
	printf("******  0. exit  ******\n");
	printf("***********************\n");
}

void game()
{
	char board[ROW][COL];
	char ret = 0;
	//��ʼ������Ϊ-�ո�
	InitBoard(board, ROW, COL);
	//��ӡһ������ -�����Ǵ�ӡ����
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if ('C' != ret)
			break;

		//��������
		ComputerGame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if ('C' != ret)
			break;
	}
	if ('*' == ret)
	{
		printf("���Ӯ\n");
	}
	else if ('#' == ret)
	{
		printf("����Ӯ\n");
	}
	else if ('Q' == ret)
	{
		printf("ƽ��\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("��ѡ��:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("��Ϸ\n");
			game();
			break;
		case 0:
			printf("����\0");
			break;
		default:
			printf("ѡ���������ѡ��\n");
		}
	} while (input);


	return 0;
}