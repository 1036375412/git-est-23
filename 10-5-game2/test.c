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
	//��ʼ�� 
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//д������
	DisplayBoard(show, ROW, COL);
	//����
	Putgame(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	
	//����
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
			printf("���������������\n");
			break;
		}
	} while (input);
	return 0;
}