#define _CRT_SECURE_NO_WARNINGS 
//P1101
#include <stdio.h>
#include <string.h>

char word[8] = "yizhong";
int n;
char g[105][105];
int mark[105][105];

int dx[8] = { -1,-1,-1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1,-1, 1,-1, 0, 1 };

void check(int x, int y) {
    for (int d = 0; d < 8; d++) {
        int ok = 1;
        int px[7], py[7];
        for (int k = 0; k < 7; k++) {
            int nx = x + dx[d] * k;
            int ny = y + dy[d] * k;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || g[nx][ny] != word[k]) {
                ok = 0;
                break;
            }
            px[k] = nx;
            py[k] = ny;
        }
        if (ok)
            for (int k = 0; k < 7; k++)
                mark[px[k]][py[k]] = 1;
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (g[i][j] == 'y')
                check(i, j);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar(mark[i][j] ? g[i][j] : '*');
        putchar('\n');
    }
    return 0;
}