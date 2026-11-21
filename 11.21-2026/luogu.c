#define _CRT_SECURE_NO_WARNINGS 
//P1596
#include <stdio.h>

#define MAXN 105

int n, m;
char grid[MAXN][MAXN];
int vis[MAXN][MAXN];

/* 8 个方向 */
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

/* 手写队列，最多 N*M 个格子入队 */
int qx[MAXN * MAXN], qy[MAXN * MAXN];

void bfs(int sx, int sy) {
    int head = 0, tail = 0;
    qx[tail] = sx;
    qy[tail] = sy;
    tail++;
    vis[sx][sy] = 1;

    while (head < tail) {
        int x = qx[head], y = qy[head];
        head++;

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == 'W' && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                qx[tail] = nx;
                qy[tail] = ny;
                tail++;
            }
        }
    }
}

int main(void) {
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);   /* 每行读一个字符串，自动加 '\0' */
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'W' && !vis[i][j]) {
                ans++;          /* 发现一个新水塘 */
                bfs(i, j);      /* 把整个连通块标记掉 */
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}