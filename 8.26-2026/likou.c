#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int numTrees(int n) {
    long long dp[20] = { 0 };
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[j - 1] * dp[i - j];
    return (int)dp[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", numTrees(n));
    return 0;
}