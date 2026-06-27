//游戏函数的实现
#define _CRT_SECURE_NO_WARNINGS 
#include "game.h"


void InitBoard(char board[ROWS][COLS], int r, int c, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= c; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int r, int c)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

static size_t GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] +
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

void ExpandBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int r, int c, int* win)
{
	if (x < 1 || x > r || y < 1 || y > c)
	{
		return;
	}

	if (show[x][y] != '*')
	{
		return;
	}

	size_t count = GetMineCount(mine, x, y);
	show[x][y] = (char)count + '0';
	(*win)++;

	if (count > 0)
	{
		return;
	}

	int i = 0;
	int j = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (!(i == x && j == y))
			{
				ExpandBoard(mine, show, i, j, r, c, win);
			}
		}
	}
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < r * c - EASY_COUNT)
	{
		printf("请输入要排查的坐标:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, ROW, COL);
					break;
				}
				else
				{
					int win_before = win;
					ExpandBoard(mine, show, x, y, ROW, COL, &win);
					DisplayBoard(show, ROW, COL);
					if (win > win_before)
					{
						printf("展开成功，剩余 %d 个格子\n", ROW * COL - EASY_COUNT - win);
					}
				}
			}
			else
			{
				printf("该坐标已经被排查过，不用重复排查\n");
			}
		}
		else
		{
			printf("输入的坐标非法，重新输入\n");
		}
	}
	if (win == r * c - EASY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		DisplayBoard(mine, ROW, COL);
	}
}