#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int n, a[10][10] = { 0 };
    scanf("%d", &n);

    // 方向数组：右、下、左、上
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int dir = 0;  // 起步向右
    int r = 0, c = 0;

    for (int num = 1; num <= n * n; num++) {
        a[r][c] = num;
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n
            || a[nr][nc] != 0) {
            dir = (dir + 1) % 4;
            nr = r + dr[dir];
            nc = c + dc[dir];
        }
        r = nr; c = nc;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    return 0;
}