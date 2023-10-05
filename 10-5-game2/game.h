#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define num_game 10
//≥ı ºªØ
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//board∆Â≈Ã
//–¥≥ˆ∆Â≈Ã
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//∑≈¿◊
void Putgame(char mine[ROWS][COLS], int row, int col);

//±‹¿◊
void Findgame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);