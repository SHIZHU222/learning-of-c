#define _CRT_SECURE_NO_WARNINGS 
void reverse(int* nums, int l, int r) {
    while (l < r) {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
        l++;
        r--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;               // k 可能大于 n
    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}