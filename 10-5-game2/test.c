#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("************************\n");
	printf("******* 1. game ********\n");
	printf("******* 0. exit ********\n");
	printf("************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };// '0' '1'
	char show[ROWS][COLS] = { 0 };// '*'
	//初始化 
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//写出棋盘
	DisplayBoard(show, ROW, COL);
	//放雷
	Putgame(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	
	//避雷
	Findgame(mine, show, ROW, COL);


}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}