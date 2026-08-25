#include <stdlib.h>

typedef struct {
    int key;   /* 数值 */
    int val;   /* 下标 */
} Entry;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Entry* table = (Entry*)malloc(sizeof(Entry) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        table[i].key = nums[i];
        table[i].val = i;
    }

    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    /* 暴力查找，简单可靠 */
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    return ans;
}
#define _CRT_SECURE_NO_WARNINGS 