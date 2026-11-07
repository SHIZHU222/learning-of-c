#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

/* 返回第一个 >= x 的下标（区间 [0, n)） */
static int lowerBound(const int* a, int n, long long x) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    res[0] = res[1] = -1;

    if (numsSize == 0) return res;

    const long long t = target;

    int left = lowerBound(nums, numsSize, t);
    /* 不存在：越界，或该位置不是 target */
    if (left == numsSize || nums[left] != target) return res;

    int right = lowerBound(nums, numsSize, t + 1) - 1;

    res[0] = left;
    res[1] = right;
    return res;
}