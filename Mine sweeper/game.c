#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void setboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			board[i][j] =set;
		}
	}
}
void boardprint(char board[ROW][COL], int row, int col)
{
	int i, j, m;
	for (j = 0;j <= col;j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 0;i < row;i++)
	{
		printf("%d", i+1);
		for (m = 0;m < col;m++)
		{
			printf(" %c", board[i][m]);
		}
		printf("\n");
	}
}
void setmine(char mine[ROW][COL], int row, int col,int count)
{
	int x, y;
	while (count)
	{
		x = rand() % col;
		y = rand() % row;
		if (x <= col && y <= row && mine[y][x] == set);
		{
			mine[y][x] = '#';
		}
		count--;
	}
}
int get_mine_count(char mine[ROW][COL], int y, int x, int row, int col)
{
	int i, j;
	int count = 0;
	for (i = y - 1, j = x - 1;j <= x + 1;j++)
	{
		if (i >= row || j >= col|| i <= 0 || j <= 0)
			continue;
		else if (mine[i][j] == '#')
		{
			count++;
		}
	}
	for (i = y, j = x - 1;j <= x + 1;j++)
	{
		if (i >= row || j >= col || i <= 0 || j <= 0)
			continue;
		else if (mine[i][j] == '#')
		{
			count++;
		}
	}
	for (i = y+1, j = x - 1;j <= x + 1;j++)
	{
		if (i >= row || j >= col || i <= 0 || j <= 0)
			continue;
		else if (mine[i][j] == '#')
		{
			count++;
		}
	}
	return count;
}
void playermove(char board[ROW][COL], char mine[ROW][COL], int row, int col)
{
	printf("your turn>");
	int x = 0;
	int y = 0;
	int z = 0;
	while (1)
	{
		printf("your x>");
		scanf("%d", &x);
		printf("\n");
		printf("your y>");
		scanf("%d", &y);
		printf("\n");
		if (x <= col && y <= row && board[y - 1][x - 1] == set)
		{
			if (mine[y - 1][x - 1] == '#')
			{
				printf("you are a loser\n");
				break;
			}
			else
			{
		/* z = get_mine_count(mine, y - 1, x - 1, ROW, COL);
		 board[y - 1][x - 1] = z + '0';*/
		 surround(mine, board, ROW, COL, y - 1, x - 1);
		 break;
			}
		}
		else
		{
			printf("your input is not right\n");
		}
	}

			
}
int surround(char mine[ROW][COL], char board[ROW][COL], int row, int col, int y, int x)
{
	if (y >= row || x >= col || y <  0 || x <  0||board[y][x]!=set||mine[y][x]=='#')
	{
		return 0;
	}
	else
	{   
		int z;
		z = get_mine_count(mine, y    , x    , ROW, COL);
		board[y ][x ] = z + '0';
		if (board[y][x] == '0')
		{
	  surround(mine, board, ROW, COL, y - 1, x - 1);
			surround(mine, board, ROW, COL, y - 1, x);
			surround(mine, board, ROW, COL, y - 1, x + 1);
		  surround(mine, board, ROW, COL, y, x - 1);
			surround(mine, board, ROW, COL, y, x + 1);
			   surround(mine, board, ROW, COL, y + 1, x - 1);
			surround(mine, board, ROW, COL, y + 1, x);
			surround(mine, board, ROW, COL, y + 1, x + 1);

		}
		else
		{
			return 0;
		}

	}

}
int judge(char board[ROW][COL], int row, int col,int count)
{
	int i, j;
	int win = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] != set)
			{
				win++;
			}
			if (win == row * col - count)
			{
				return 1;
			}
		}
	}
	return 0;
}