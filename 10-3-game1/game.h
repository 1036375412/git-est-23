#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

//��ʼ������Ϊ-�ո�
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerGame(char board[ROW][COL], int row, int col);



//���Ӯ  ����*
//����Ӯ  ����#
//ƽ��    ����Q
//����    ����C

char IsWin(char board[ROW][COL], int row, int col);