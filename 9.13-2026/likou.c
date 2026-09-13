#define _CRT_SECURE_NO_WARNINGS 
int maxSubArray(int* nums, int numsSize) {
    int cur = nums[0];   // 以当前位置结尾的最大子数组和
    int ans = nums[0];   // 全局最大和
    for (int i = 1; i < numsSize; i++) {
        // 要么接上前面的和，要么从当前元素重新开始
        cur = (cur > 0 ? cur : 0) + nums[i];
        if (cur > ans) ans = cur;
    }
    return ans;
}