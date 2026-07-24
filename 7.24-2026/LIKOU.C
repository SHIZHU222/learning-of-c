#define max(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    int a = 0, b = 0;          // dp[i-2], dp[i-1]
    for (int i = 0; i < numsSize; i++) {
        int c = max(b, a + nums[i]);
        a = b;
        b = c;
    }
    return b;
}