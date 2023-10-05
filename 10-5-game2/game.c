#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//board����
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
//д������
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("-----ɨ����Ϸ------\n");
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----ɨ����Ϸ------\n");
}
//����
void Putgame(char mine[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < num_game)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}
//�����׵ĸ���
int count_num_game(char mine[ROWS][COLS], int x, int y)
{
	int count = 0;
	int i = x-1;
	int j = y-1;
	for (i; i <= x + 1; i++)
	{
		for (j; j <= y + 1; j++)
		{
			if (mine[i][j] == '1')
				count++;
		}
	}
	return count;
}
//����
void Findgame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count < row * col - num_game)
	{
		int i = 0;
		int j = 0;
		scanf("%d%d", &i, &j);
		if (i > 0 && i <= row && j > 0 && j <= col)
		{
			if (mine[i][j] == '1')
			{
				printf("��Ϸʧ��\n");
				break;
			}
			else
			{
				int ret = count_num_game(mine, i ,j);
				show[i][j] = ret + '0';
				DisplayBoard(show, row, col);
				count++;
			}
		}
		else
			printf("����Ƿ�����������\n");
	}
	if (count == row * col - num_game)
	{
		printf("��ϲ���ʤ��\n");
		DisplayBoard(show, row, col);
	}
}