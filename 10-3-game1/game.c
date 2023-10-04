#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		printf("玩家下：\n");
		scanf("%d%d", &i, &j);

		if (i-1 >= 0 && i-1 < row && j-1 >= 0 && j-1 < col)
		{
			if (board[i-1][j-1] == ' ')
			{
				board[i-1][j-1] = '*';
				break;
			}
			else 
			{
				printf("被占用，重新输入\n");
			}
		}
		else
		{
			printf("输入非法，重新输入\n");
		}
	}
}
//电脑下棋
void ComputerGame(char board[ROW][COL], int row, int col)
{
	printf("电脑下：\n");
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
}

//棋盘是否满
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ');//未满
			return 0;
		}
	}
	return 1;
}


//判断是否赢
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
			break;//
		}
	}
	//列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
			break;
		}
	}
	//对角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	int ret = IsFull(board, row, col);
	if (1 == ret)
		return 'Q';
	return 'C';
}