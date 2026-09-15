#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

// qsort 比较函数：按起点升序
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
    int* returnSize, int** returnColumnSizes) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // 按起点排序
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // 结果数组（最多 intervalsSize 个）
    int** res = (int**)malloc(sizeof(int*) * intervalsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * intervalsSize);

    int count = 0;
    res[count] = (int*)malloc(sizeof(int) * 2);
    res[count][0] = intervals[0][0];
    res[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    for (int i = 1; i < intervalsSize; i++) {
        int last = count - 1;
        // 重叠：当前起点 <= 上一个终点
        if (intervals[i][0] <= res[last][1]) {
            if (intervals[i][1] > res[last][1])
                res[last][1] = intervals[i][1];
        }
        else {
            res[count] = (int*)malloc(sizeof(int) * 2);
            res[count][0] = intervals[i][0];
            res[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return res;
}