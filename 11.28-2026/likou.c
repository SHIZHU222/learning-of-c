#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    /* 和为奇数，无法平分 */
    if (sum & 1) return false;

    int target = sum / 2;

    /* dp[j] 表示能否凑出和为 j */
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;

    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        /* 必须倒序，保证每个数只用一次 */
        for (int j = target; j >= v; j--) {
            if (dp[j - v]) {
                dp[j] = true;
            }
        }
    }

    bool res = dp[target];
    free(dp);
    return res;
}