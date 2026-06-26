//P1002
#include <stdio.h>
int main()
{
    int n, m, hx, hy;
    scanf("%d %d %d %d", &n, &m, &hx, &hy);
    int dx[9] = { 0, -2, -2, -1, -1,  1, 1,  2, 2 };
    int dy[9] = { 0, -1,  1, -2,  2, -2, 2, -1, 1 };

    int block[21][21] = { 0 };
    for (int k = 0; k < 9; k++) {
        int x = hx + dx[k];
        int y = hy + dy[k];
        if (x >= 0 && x <= n && y >= 0 && y <= m)
            block[x][y] = 1;
    }

    long long dp[21][21] = { 0 };
    dp[0][0] = block[0][0] ? 0 : 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (block[i][j] || (i == 0 && j == 0)) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    printf("%lld\n", dp[n][m]);
    return 0;
}