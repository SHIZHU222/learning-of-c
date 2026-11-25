#define _CRT_SECURE_NO_WARNINGS 
//P1825
#include <stdio.h>

#define MAXN 305

int n, m;
char g[MAXN][MAXN];
int dist[MAXN][MAXN];

int qx[MAXN * MAXN], qy[MAXN * MAXN];

/* 每个字母的两个端点位置 */
int lx[26][2], ly[26][2], lc[26];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {
    scanf("%d %d", &n, &m);

    int sx = -1, sy = -1;

    for (int i = 0; i < n; i++) {
        scanf("%s", g[i]);
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '@') {
                sx = i;
                sy = j;
            }
            else if (g[i][j] >= 'A' && g[i][j] <= 'Z') {
                int id = g[i][j] - 'A';
                lx[id][lc[id]] = i;
                ly[id][lc[id]] = j;
                lc[id]++;
            }
            dist[i][j] = -1;
        }
    }

    /* BFS */
    int head = 0, tail = 0;
    qx[tail] = sx;
    qy[tail] = sy;
    tail++;
    dist[sx][sy] = 0;

    while (head < tail) {
        int x = qx[head], y = qy[head];
        head++;

        if (g[x][y] == '=') {          /* 到达出口 */
            printf("%d\n", dist[x][y]);
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '#') continue;

            int tx = nx, ty = ny;

            /* 踩到滑梯端点 → 强制传送到另一端点 */
            if (g[nx][ny] >= 'A' && g[nx][ny] <= 'Z') {
                int id = g[nx][ny] - 'A';
                if (lx[id][0] == nx && ly[id][0] == ny) {
                    tx = lx[id][1];
                    ty = ly[id][1];
                }
                else {
                    tx = lx[id][0];
                    ty = ly[id][0];
                }
            }

            if (dist[tx][ty] != -1) continue;

            dist[tx][ty] = dist[x][y] + 1;
            qx[tail] = tx;
            qy[tail] = ty;
            tail++;
        }
    }

    return 0;
}