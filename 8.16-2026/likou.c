#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>

#define OFFSET 10000
#define SIZE   20001

int longestSubsequence(int* arr, int arrSize, int difference) {
    int dp[SIZE];
    memset(dp, 0, sizeof(dp));

    int ans = 0;
    for (int i = 0; i < arrSize; i++) {
        int x = arr[i] + OFFSET;
        int prev = x - difference;
        int len = 1;
        if (prev >= 0 && prev < SIZE)
            len = dp[prev] + 1;
        dp[x] = len;
        if (len > ans) ans = len;
    }
    return ans;
}