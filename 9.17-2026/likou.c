#define _CRT_SECURE_NO_WARNINGS 
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    // 先算左侧乘积
    ans[0] = 1;
    for (int i = 1; i < numsSize; i++)
        ans[i] = ans[i - 1] * nums[i - 1];

    // 再从右往左乘上右侧乘积
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= right;
        right *= nums[i];
    }
    return ans;
}