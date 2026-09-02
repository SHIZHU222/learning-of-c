#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

typedef struct {
    int key;   // 数值
    int val;   // 下标
} Pair;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int size = numsSize * 2 + 1;
    Pair* table = (Pair*)calloc(size, sizeof(Pair));
    for (int i = 0; i < size; i++) table[i].val = -1;  // -1 表示空

    int* ans = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        int need = target - nums[i];
        int h = (need % size + size) % size;   // 处理负数取模
        // 线性探测查找 need
        while (table[h].val != -1 && table[h].key != need)
            h = (h + 1) % size;
        if (table[h].val != -1) {   // 找到了
            ans[0] = table[h].val;
            ans[1] = i;
            *returnSize = 2;
            free(table);
            return ans;
        }
        // 插入当前值
        h = (nums[i] % size + size) % size;
        while (table[h].val != -1)
            h = (h + 1) % size;
        table[h].key = nums[i];
        table[h].val = i;
    }
    *returnSize = 0;
    free(table);
    return ans;
}