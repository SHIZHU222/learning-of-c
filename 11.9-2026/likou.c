#define _CRT_SECURE_NO_WARNINGS 
int findMin(int* nums, int numsSize) {
    int lo = 0, hi = numsSize - 1;   /* 最小值一定在 [lo, hi] 内 */

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi])
            lo = mid + 1;    /* 断点在右边 */
        else
            hi = mid;        /* 断点在 mid 或左边 */
    }
    return nums[lo];
}