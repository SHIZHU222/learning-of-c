#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

static void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int target = numsSize - k;       /* 升序下第 k 大的下标 */
    int lo = 0, hi = numsSize - 1;

    while (lo <= hi) {
        /* 随机基准，避免有序/特殊输入退化 */
        int r = lo + rand() % (hi - lo + 1);
        int pivot = nums[r];

        /* 三路划分：nums[lo..lt) < pivot, nums[lt..gt] == pivot, nums(gt..hi] > pivot */
        int lt = lo, i = lo, gt = hi;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(&nums[lt], &nums[i]);
                lt++; i++;
            }
            else if (nums[i] > pivot) {
                swap(&nums[i], &nums[gt]);
                gt--;                 /* 换过来的元素还没检查，i 不动 */
            }
            else {
                i++;                  /* 等于 pivot，留在中间 */
            }
        }

        if (target < lt)        hi = lt - 1;        /* 在左段 */
        else if (target > gt)   lo = gt + 1;        /* 在右段 */
        else                    return nums[target];/* 落在等于段 */
    }
    return -1;
}