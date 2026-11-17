#define _CRT_SECURE_NO_WARNINGS 
//P2895
#include <stdio.h>
#include <string.h>

#define SZ  305
#define INF 0x3f3f3f3f

int burn[SZ][SZ];   /* 格子被毁的最早时刻 */
int dist[SZ][SZ];   /* BFS 到达时间，-1 表示未访问 */

int qx[SZ * SZ], qy[SZ * SZ];

int main(void) {
    int M;
    scanf("%d", &M);

    memset(burn, 0x3f, sizeof(burn));      /* 初始化为 INF */

    int dx5[5] = { 0, 1, -1, 0, 0 };
    int dy5[5] = { 0, 0, 0, 1, -1 };

    for (int i = 0; i < M; i++) {
        int x, y, t;
        scanf("%d %d %d", &x, &y, &t);

        for (int k = 0; k < 5; k++) {      /* 中心 + 四个邻居 */
            int nx = x + dx5[k], ny = y + dy5[k];
            if (nx >= 0 && nx < SZ && ny >= 0 && ny < SZ && t < burn[nx][ny])
                burn[nx][ny] = t;
        }
    }

    /* 起点在时刻 0 就被毁：她无法在原点存活 */
    if (burn[0][0] == 0) {
        printf("-1\n");
        return 0;
    }

    /* 起点永远安全 —— 已经是答案 */
    if (burn[0][0] == INF) {
        printf("0\n");
        return 0;
    }

    memset(dist, -1, sizeof(dist));

    int head = 0, tail = 0;
    dist[0][0] = 0;
    qx[tail] = 0; qy[tail] = 0; tail++;

    int dx4[4] = { 1, -1, 0, 0 };
    int dy4[4] = { 0, 0, 1, -1 };

    while (head < tail) {
        int cx = qx[head], cy = qy[head];
        head++;

        for (int k = 0; k < 4; k++) {
            int nx = cx + dx4[k], ny = cy + dy4[k];

            if (nx < 0 || nx >= SZ || ny < 0 || ny >= SZ) continue;
            if (dist[nx][ny] != -1) continue;

            int nt = dist[cx][cy] + 1;

            /* 必须在被毁之前到达 */
            if (nt >= burn[nx][ny]) continue;

            dist[nx][ny] = nt;

            /* 永远安全 → 找到答案 */
            if (burn[nx][ny] == INF) {
                printf("%d\n", nt);
                return 0;
            }

            qx[tail] = nx; qy[tail] = ny; tail++;
        }
    }

    printf("-1\n");   /* 无处可逃 */
    return 0;
}