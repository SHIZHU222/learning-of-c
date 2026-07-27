#define _CRT_SECURE_NO_WARNINGS 
#define min(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = *gridColSize;
    int dp[200] = { 0 };

    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++)
        dp[j] = dp[j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        dp[0] += grid[i][0];                         // 每行第一列
        for (int j = 1; j < n; j++)
            dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
    }
    return dp[n - 1];
}