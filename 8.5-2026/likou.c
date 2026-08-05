#define _CRT_SECURE_NO_WARNINGS 
#define min(a, b) ((a) < (b) ? (a) : (b))

int minDistance(char* word1, char* word2) {
    int m = strlen(word1), n = strlen(word2);
    int dp[501];                          // 一维滚动数组

    for (int j = 0; j <= n; j++) dp[j] = j;  // 空串→word2 全部插入

    for (int i = 1; i <= m; i++) {
        int prev = dp[0];                 // 存 dp[i-1][j-1]
        dp[0] = i;                        // word1→空串 全部删除
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (word1[i - 1] == word2[j - 1])
                dp[j] = prev;
            else
                dp[j] = 1 + min(min(dp[j], dp[j - 1]), prev);
            prev = temp;
        }
    }
    return dp[n];
}