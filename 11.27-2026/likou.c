#define _CRT_SECURE_NO_WARNINGS 
int maxProduct(int* nums, int numsSize) {
    long long curMax = nums[0];
    long long curMin = nums[0];
    long long ans = nums[0];

    for (int i = 1; i < numsSize; i++) {
        long long a = nums[i];
        long long p1 = curMax * a;   /* 最大 × 当前 */
        long long p2 = curMin * a;   /* 最小 × 当前 */

        long long newMax = a;
        long long newMin = a;

        if (p1 > newMax) newMax = p1;
        if (p2 > newMax) newMax = p2;
        if (p1 < newMin) newMin = p1;
        if (p2 < newMin) newMin = p2;

        curMax = newMax;
        curMin = newMin;

        if (curMax > ans) ans = curMax;
    }

    return (int)ans;   /* 题目保证答案在 32 位整数范围内 */
}