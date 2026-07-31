#define _CRT_SECURE_NO_WARNINGS 
#define min(a, b) ((a) < (b) ? (a) : (b))

int maximalSquare(char** matrix, int m, int* colSize) {
    int n = *colSize, dp[301] = { 0 };
    int maxSide = 0, prev = 0;                  // prev 存 dp[i-1][j-1]

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int temp = dp[j];                    // 存当前格的旧值（作为下一轮的左上角）
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0)
                    dp[j] = 1;
                else
                    dp[j] = min(min(dp[j], dp[j - 1]), prev) + 1;
                if (dp[j] > maxSide) maxSide = dp[j];
            }
            else {
                dp[j] = 0;
            }
            prev = temp;
        }
    }
    return maxSide * maxSide;                    // 面积 = 边长²
}