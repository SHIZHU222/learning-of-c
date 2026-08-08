#define _CRT_SECURE_NO_WARNINGS 
//P1004
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, g[10][10] = { 0 }, dp[10][10][10][10] = { 0 };
    scanf("%d", &n);

    int x, y, v;
    while (scanf("%d%d%d", &x, &y, &v) && (x || y || v))
        g[x][y] = v;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int l = 1; l <= n; l++) {
                    int best = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]),
                        max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]));
                    dp[i][j][k][l] = best + g[i][j];
                    if (i != k || j != l)
                        dp[i][j][k][l] += g[k][l];
                }

    printf("%d\n", dp[n][n][n][n]);
    return 0;
}