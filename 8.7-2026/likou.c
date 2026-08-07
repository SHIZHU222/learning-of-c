#define _CRT_SECURE_NO_WARNINGS 
int lengthOfLIS(int* nums, int numsSize) {
    int tails[2500], len = 0;
    for (int i = 0; i < numsSize; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) / 2;
            if (tails[mid] < nums[i]) l = mid + 1;
            else r = mid;
        }
        tails[l] = nums[i];
        if (l == len) len++;
    }
    return len;
}
//
