#define _CRT_SECURE_NO_WARNINGS 
int search(int* nums, int numsSize, int target) {
    int lo = 0, hi = numsSize - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) return mid;

        if (nums[lo] <= nums[mid]) {
            /* 左半 [lo, mid] 有序 */
            if (nums[lo] <= target && target < nums[mid])
                hi = mid - 1;          /* target 在左半 */
            else
                lo = mid + 1;          /* target 在右半 */
        }
        else {
            /* 右半 [mid, hi] 有序 */
            if (nums[mid] < target && target <= nums[hi])
                lo = mid + 1;          /* target 在右半 */
            else
                hi = mid - 1;          /* target 在左半 */
        }
    }
    return -1;
}