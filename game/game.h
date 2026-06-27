#pragma once
//游戏函数的声明
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int r, int c, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int r, int c);

//布置雷
void SetMine(char board[ROWS][COLS], int r, int c);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c);

//展开一片
void ExpandBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int r, int c, int* win);
