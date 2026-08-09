#define _CRT_SECURE_NO_WARNINGS 
#define max(a, b) ((a) > (b) ? (a) : (b))

int longestArithSeqLength(int* nums, int n) {
    int dp[1000][1001] = { 0 };    // 偏移量 500，公差范围 ±500
    int ans = 1;

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            int d = nums[j] - nums[i] + 500;   // 偏移到 [0, 1000]
            if (dp[i][d] == 0)
                dp[j][d] = 2;                  // 新序列：nums[i], nums[j]
            else
                dp[j][d] = dp[i][d] + 1;
            ans = max(ans, dp[j][d]);
        }
    }
    return ans;
}