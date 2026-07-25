#define _CRT_SECURE_NO_WARNINGS 
#define max(a, b) ((a) > (b) ? (a) : (b))

int deleteAndEarn(int* nums, int numsSize) {
    int maxVal = 0;
    for (int i = 0; i < numsSize; i++)
        maxVal = max(maxVal, nums[i]);

    int* sum = (int*)calloc(maxVal + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++)
        sum[nums[i]] += nums[i];

    int a = 0, b = sum[0];             // dp[i-2], dp[i-1]
    for (int i = 1; i <= maxVal; i++) {
        int c = max(b, a + sum[i]);
        a = b;
        b = c;
    }
    free(sum);
    return b;
}