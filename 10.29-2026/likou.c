#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdbool.h>

static void backtrack(int* nums, int numsSize, int* path, bool* used, int depth,
    int** result, int* returnSize, int** returnColumnSizes) {
    if (depth == numsSize) {
        int idx = (*returnSize)++;
        result[idx] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; i++) {
            result[idx][i] = path[i];
        }
        (*returnColumnSizes)[idx] = numsSize;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        used[i] = true;
        path[depth] = nums[i];

        backtrack(nums, numsSize, path, used, depth + 1,
            result, returnSize, returnColumnSizes);

        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 2; i <= numsSize; i++) {
        total *= i;
    }

    int** result = (int**)malloc(sizeof(int*) * total);
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * numsSize);
    bool* used = (bool*)calloc(numsSize, sizeof(bool));

    backtrack(nums, numsSize, path, used, 0,
        result, returnSize, returnColumnSizes);

    free(path);
    free(used);

    return result;
}