#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

static void dfs(int* nums, int numsSize, int start,
    int* path, int depth,
    int** result, int* returnSize,
    int* returnColumnSizes) {
    int pos = (*returnSize)++;

    result[pos] = (int*)malloc(sizeof(int) * (depth == 0 ? 1 : depth));

    for (int i = 0; i < depth; i++) {
        result[pos][i] = path[i];
    }

    returnColumnSizes[pos] = depth;

    for (int i = start; i < numsSize; i++) {
        path[depth] = nums[i];
        dfs(nums, numsSize, i + 1, path, depth + 1,
            result, returnSize, returnColumnSizes);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize,
    int** returnColumnSizes) {
    int total = 1 << numsSize;

    int** result = (int**)malloc(sizeof(int*) * total);
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * (numsSize == 0 ? 1 : numsSize));

    dfs(nums, numsSize, 0, path, 0,
        result, returnSize, *returnColumnSizes);

    free(path);
    return result;
}