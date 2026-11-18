#define _CRT_SECURE_NO_WARNINGS 
//P1605
#include <stdio.h>

int n, m, t;
int sx, sy, fx, fy;
int blocked[10][10];   /* 障碍标记 */
int vis[10][10];       /* 访问标记 */
int ans = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y) {
    if (x == fx && y == fy) {   /* 到达终点 */
        ans++;
        return;
    }

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 1 || nx > n || ny < 1 || ny > m) continue;  /* 越界 */
        if (blocked[nx][ny]) continue;                       /* 障碍 */
        if (vis[nx][ny]) continue;                           /* 已走过 */

        vis[nx][ny] = 1;      /* 标记 */
        dfs(nx, ny);          /* 递归 */
        vis[nx][ny] = 0;      /* 回溯：撤销标记 */
    }
}

int main(void) {
    scanf("%d %d %d", &n, &m, &t);
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);

    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        blocked[x][y] = 1;
    }

    vis[sx][sy] = 1;   /* 起点先标记 */
    dfs(sx, sy);

    printf("%d\n", ans);
    return 0;
}