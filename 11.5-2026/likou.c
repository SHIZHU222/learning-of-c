#define _CRT_SECURE_NO_WARNINGS
int searchInsert(int* nums, int numsSize, int target) {
    int lo = 0, hi = numsSize;      /* 区间为 [lo, hi) */

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target)
            lo = mid + 1;           /* mid 及其左边都不可能是答案 */
        else
            hi = mid;               /* mid 可能是答案，保留 */
    }
    return lo;                      /* lo == hi，即第一个 >= target 的位置 */
}