#define _CRT_SECURE_NO_WARNINGS 
#define max(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLIS(int* nums, int numsSize) {
    int dp[2500], ans = 1;
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}