#define _CRT_SECURE_NO_WARNINGS \
#include <stdlib.h>

long long max(long long a, long long b) { return a > b ? a : b; }

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    int n = questionsSize;
    long long* dp = (long long*)calloc(n + 1, sizeof(long long));
    // dp[n] = 0 已初始化

    for (int i = n - 1; i >= 0; i--) {
        int p = questions[i][0];
        int b = questions[i][1];
        int next = i + b + 1;
        long long solve = p + (next < n ? dp[next] : 0);
        dp[i] = max(dp[i + 1], solve);
    }

    long long ans = dp[0];
    free(dp);
    return ans;
}