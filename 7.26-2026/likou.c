#define _CRT_SECURE_NO_WARNINGS 
int uniquePaths(int m, int n) {
    int dp[100] = { 0 };          // 题目一般 m,n ≤ 100
    for (int j = 0; j < n; j++) dp[j] = 1;

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[j] += dp[j - 1];

    return dp[n - 1];
}
//
long long C(int n, int k) {
    long long res = 1;
    if (k > n - k) k = n - k;       // 取较小者减少计算
    for (int i = 0; i < k; i++)
        res = res * (n - i) / (i + 1);
    return res;
}

int uniquePaths(int m, int n) {
    return (int)C(m + n - 2, m - 1);
}