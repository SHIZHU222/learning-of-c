#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

static int cmp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

static void dfs(int* candidates, int candidatesSize, int start, int remain,
    int* path, int depth, int** result, int* returnSize,
    int* returnColumnSizes) {
    if (remain == 0) {
        int index = (*returnSize)++;

        result[index] = (int*)malloc(sizeof(int) * depth);
        for (int i = 0; i < depth; i++) {
            result[index][i] = path[i];
        }

        returnColumnSizes[index] = depth;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > remain) {
            break;
        }

        path[depth] = candidates[i];
        dfs(candidates, candidatesSize, i, remain - candidates[i],
            path, depth + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
    int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);

    int** result = (int**)malloc(sizeof(int*) * 150);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
    *returnSize = 0;

    int* path = (int*)malloc(sizeof(int) * (target + 1));

    dfs(candidates, candidatesSize, 0, target,
        path, 0, result, returnSize, *returnColumnSizes);

    free(path);
    return result;
}