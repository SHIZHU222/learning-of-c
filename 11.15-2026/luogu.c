#define _CRT_SECURE_NO_WARNINGS 
//P1433
#include <stdio.h>
#include <math.h>

#define MAXN 16
#define INF 1e18

double x[MAXN], y[MAXN];
double d[MAXN][MAXN];          /* 两两距离 */
double dp[1 << 15][MAXN];      /* 状压 DP */

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &x[i], &y[i]);

    /* 把起点 (0,0) 当作第 n 个点 */
    x[n] = 0.0;
    y[n] = 0.0;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            d[i][j] = sqrt(dx * dx + dy * dy);
        }

    int full = 1 << n;

    /* 初始化 */
    for (int mask = 0; mask < full; mask++)
        for (int i = 0; i < n; i++)
            dp[mask][i] = INF;

    for (int i = 0; i < n; i++)
        dp[1 << i][i] = d[n][i];        /* 起点 -> 第 i 块 */

    /* 状压 DP */
    for (int mask = 1; mask < full; mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask >> i & 1)) continue;   /* i 必须在集合里 */
            if (dp[mask][i] >= INF) continue;

            for (int j = 0; j < n; j++) {
                if (mask >> j & 1) continue;  /* j 还没吃过 */

                int nm = mask | (1 << j);
                double nd = dp[mask][i] + d[i][j];
                if (nd < dp[nm][j]) dp[nm][j] = nd;
            }
        }
    }

    /* 吃完所有奶酪，取最小的终点 */
    double ans = INF;
    for (int i = 0; i < n; i++)
        if (dp[full - 1][i] < ans) ans = dp[full - 1][i];

    printf("%.2f\n", ans);
    return 0;
}