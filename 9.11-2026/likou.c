#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

int cmp(const void* pa, const void* pb) {
    return *(const int*)pa - *(const int*)pb;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int cap = 16, cnt = 0;
    int** ans = malloc(cap * sizeof(int*));
    *returnColumnSizes = malloc(cap * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // 去重 i
        int l = i + 1, r = numsSize - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                int* tri = malloc(3 * sizeof(int));
                tri[0] = nums[i]; tri[1] = nums[l]; tri[2] = nums[r];
                if (cnt == cap) {
                    cap *= 2;
                    ans = realloc(ans, cap * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                }
                ans[cnt] = tri;
                (*returnColumnSizes)[cnt] = 3;
                cnt++;
                while (l < r && nums[l] == nums[l + 1]) l++;  // 去重 l
                while (l < r && nums[r] == nums[r - 1]) r--;  // 去重 r
                l++; r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    *returnSize = cnt;
    return ans;
}