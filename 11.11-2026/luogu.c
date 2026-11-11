#define _CRT_SECURE_NO_WARNINGS 
//P1443
#include <stdio.h>
#include <string.h>

#define MAX 405

int dist[MAX][MAX];          /* 最少步数，-1 表示不可达 */
int qx[MAX * MAX], qy[MAX * MAX];   /* 手写队列 */

const int dx[8] = { 2,  2, -2, -2,  1,  1, -1, -1 };
const int dy[8] = { 1, -1,  1, -1,  2, -2,  2, -2 };

int main(void) {
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);

    memset(dist, -1, sizeof(dist));     /* 全部初始化为 -1 */

    int head = 0, tail = 0;
    dist[x][y] = 0;
    qx[tail] = x; qy[tail] = y;
    tail++;

    while (head < tail) {
        int cx = qx[head], cy = qy[head];
        head++;

        for (int k = 0; k < 8; k++) {
            int nx = cx + dx[k], ny = cy + dy[k];

            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;  /* 越界 */
            if (dist[nx][ny] != -1) continue;                    /* 已访问 */

            dist[nx][ny] = dist[cx][cy] + 1;
            qx[tail] = nx; qy[tail] = ny;
            tail++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d", dist[i][j]);
            putchar(j == m ? '\n' : ' ');
        }
    }
    return 0;
}
