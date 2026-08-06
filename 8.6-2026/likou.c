#define _CRT_SECURE_NO_WARNINGS 
#define max(a, b) ((a) > (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int total = 0;
    for (int i = 0; i < m; i++) total += s1[i];
    for (int j = 0; j < n; j++) total += s2[j];

    int dp[1002] = { 0 };                         // 一维滚动

    for (int i = 0; i < m; i++) {
        int prev = 0;                            // dp[i-1][j-1]
        for (int j = 0; j < n; j++) {
            int temp = dp[j + 1];                // dp[i-1][j] (旧值，下一轮的左上方)
            if (s1[i] == s2[j])
                dp[j + 1] = prev + s1[i];        // 匹配，累加 ASCII
            else
                dp[j + 1] = max(dp[j + 1], dp[j]);
            prev = temp;
        }
    }
    return total - 2 * dp[n];
}
//
#define min(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int dp[1002];
    for (int j = 0; j <= n; j++) {
        dp[j] = 0;
        for (int k = 0; k < j; k++) dp[j] += s2[k];  // dp[0][j]
    }
    for (int i = 1; i <= m; i++) {
        int prev = dp[0];
        dp[0] += s1[i - 1];                           // dp[i][0]
        for (int j = 1; j <= n; j++) {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1])
                dp[j] = prev;
            else
                dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
            prev = temp;
        }
    }
    return dp[n];
}