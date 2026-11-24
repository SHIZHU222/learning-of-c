#define _CRT_SECURE_NO_WARNINGS 
//P1162
#include <stdio.h>

int n;
int a[35][35];      /* 下标 1..n，外围一圈默认为 0 */
int vis[35][35];
int qx[1100], qy[1100];   /* (n+2)^2 ≈ 1024 */

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {
    scanf("%d", &n);

    /* 读入：兼容「空格分隔」和「连续数字」两种输入 */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char ch;
            do {
                ch = getchar();
            } while (ch != '0' && ch != '1');
            a[i][j] = ch - '0';
        }
    }

    /* 从外圈 (0,0) 开始 BFS，标记所有能到达的 0（即圈外） */
    int head = 0, tail = 0;
    qx[tail] = 0;
    qy[tail] = 0;
    tail++;
    vis[0][0] = 1;

    while (head < tail) {
        int x = qx[head], y = qy[head];
        head++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx > n + 1 || ny < 0 || ny > n + 1) continue;
            if (a[nx][ny] == 0 && !vis[nx][ny]) {
                vis[nx][ny] = 1;
                qx[tail] = nx;
                qy[tail] = ny;
                tail++;
            }
        }
    }

    /* 输出：未被访问的 0 就是圈内，输出 2 */
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) putchar(' ');
            if (a[i][j] == 0 && !vis[i][j]) {
                putchar('2');
            }
            else {
                putchar('0' + a[i][j]);   /* 0 或 1 */
            }
        }
        putchar('\n');
    }

    return 0;
}