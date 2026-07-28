#define _CRT_SECURE_NO_WARNINGS 
int uniquePathsWithObstacles(int** grid, int m, int* colSize) {
    int n = *colSize;
    int dp[100] = { 0 };

    dp[0] = (grid[0][0] == 0);          // 起点是障碍直接 0
    for (int j = 1; j < n; j++)
        dp[j] = grid[0][j] ? 0 : dp[j - 1];  // 第一行只能从左来

    for (int i = 1; i < m; i++) {
        if (grid[i][0]) dp[0] = 0;       // 第一列有障碍则后面全是 0
        for (int j = 1; j < n; j++)
            dp[j] = grid[i][j] ? 0 : dp[j] + dp[j - 1];
    }
    return dp[n - 1];
}