#pragma once
#include<stdio.h>
#define ROW 10
#define COL 10
#define EASY_COUNT 5
#define set '*'
void boardprint(char board[ROW][COL], int row, int col);
void setboard(char board[ROW][COL], int row, int col);
void setmine(char mine[ROW][COL], int row, int col, int count);
void playermove(char board[ROW][COL], char mine[ROW][COL], int row, int col);
int judge(char board[ROW][COL], int row, int col, int count);