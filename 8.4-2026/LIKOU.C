#define _CRT_SECURE_NO_WARNINGS 
#define max(a, b) ((a) > (b) ? (a) : (b))

int longestPalindromeSubseq(char* s) {
    int n = strlen(s);
    int dp[1000][1000] = { 0 };           // 或 malloc

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;                    // 单字符回文长度为 1
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][n - 1];
}