
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<time.h>
#include "game.h"
void openner()
{

	printf("#######################\n");
	printf("###### welcome ########\n");
	printf("##start>1    close>0##\n");
	printf("#######################\n");
	while (1)
	{
		int x = 0;
		scanf("%d", &x);
		if (x == 1)
		{
			printf("game start\n");
			break;
		}
		else if (0 == x)
		{
			printf("plese close the game by hand\n");
		}
		else
		{
			printf("i can not know what you express to me\n");
		}
	}
}
int main()
{
	int res = 0;
	srand((unsigned int)time(NULL));
	openner();
	char board [ROW] [COL] = {0};
	char mine[ROW][COL] = { 0 };
	setboard(mine, ROW, COL);
	setboard(board, ROW, COL);
	boardprint(board, ROW, COL);
	setmine(mine, ROW, COL, EASY_COUNT);
	boardprint(mine, ROW, COL);
	while (1)
	{
		playermove(board, mine, ROW, COL);
		boardprint(board, ROW, COL);
		res = judge(board, ROW, COL, EASY_COUNT);
		if (res == 1)
		{
			printf("you are winner");
			break;
		}
		printf("\n");
	}
}