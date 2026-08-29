#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <limits.h>

int numSquares(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            if (dp[i - j * j] + 1 < dp[i])
                dp[i] = dp[i - j * j] + 1;

    return dp[n];
}