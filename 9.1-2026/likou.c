#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
#include <limits.h>

int min(int a, int b) { return a < b ? a : b; }

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));
    for (int i = 0; i <= amount; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int c = 0; c < coinsSize; c++)
            if (coins[c] <= i && dp[i - coins[c]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coins[c]] + 1);

    int ans = dp[amount] == INT_MAX ? -1 : dp[amount];
    free(dp);
    return ans;
}