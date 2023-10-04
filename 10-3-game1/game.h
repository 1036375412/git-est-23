#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

//初始化棋盘为-空格
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerGame(char board[ROW][COL], int row, int col);



//玩家赢  返回*
//电脑赢  返回#
//平局    返回Q
//继续    返回C

char IsWin(char board[ROW][COL], int row, int col);