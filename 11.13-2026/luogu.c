#define _CRT_SECURE_NO_WARNINGS 
//P1135
#include <stdio.h>
#include <string.h>

int main(void) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int k[205];
    for (int i = 1; i <= n; i++) scanf("%d", &k[i]);

    int dist[205];
    memset(dist, -1, sizeof(dist));   /* -1 表示未到达 */

    int q[205], head = 0, tail = 0;
    dist[a] = 0;
    q[tail++] = a;

    while (head < tail) {
        int cur = q[head++];
        if (cur == b) break;          /* 提前结束（可选） */

        int next[2] = { cur + k[cur], cur - k[cur] };
        for (int t = 0; t < 2; t++) {
            int nx = next[t];
            if (nx < 1 || nx > n) continue;      /* 楼层越界 */
            if (dist[nx] != -1) continue;        /* 已访问 */

            dist[nx] = dist[cur] + 1;
            q[tail++] = nx;
        }
    }

    printf("%d\n", dist[b]);          /* 不可达时就是 -1 */
    return 0;
}