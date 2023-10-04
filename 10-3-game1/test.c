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
	//初始化棋盘为-空格
	InitBoard(board, ROW, COL);
	//打印一下棋盘 -本质是打印数组
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if ('C' != ret)
			break;

		//电脑下棋
		ComputerGame(board, ROW, COL);
		DisplayBoard(board, ROW, COL);

		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if ('C' != ret)
			break;
	}
	if ('*' == ret)
	{
		printf("玩家赢\n");
	}
	else if ('#' == ret)
	{
		printf("电脑赢\n");
	}
	else if ('Q' == ret)
	{
		printf("平局\n");
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
		printf("请选择:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//printf("游戏\n");
			game();
			break;
		case 0:
			printf("结束\0");
			break;
		default:
			printf("选择错误，重新选择\n");
		}
	} while (input);


	return 0;
}