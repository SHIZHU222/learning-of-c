#define _CRT_SECURE_NO_WARNINGS 
int findNumberOfLIS(int* nums, int n) {
    int dp[2000] = { 0 }, cnt[2000] = { 0 };
    int maxLen = 1, ans = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = cnt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];               // 发现更长的，重置计数
                }
                else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];               // 等长方案累加
                }
            }
        }
        if (dp[i] > maxLen) maxLen = dp[i];
    }

    for (int i = 0; i < n; i++)
        if (dp[i] == maxLen) ans += cnt[i];

    return ans;
}