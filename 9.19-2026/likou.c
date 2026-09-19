#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int* res = (int*)malloc(sizeof(int) * m * n);
    *returnSize = 0;

    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)          // 向右
            res[(*returnSize)++] = matrix[top][j];
        top++;

        for (int i = top; i <= bottom; i++)          // 向下
            res[(*returnSize)++] = matrix[i][right];
        right--;

        if (top <= bottom) {                         // 向左
            for (int j = right; j >= left; j--)
                res[(*returnSize)++] = matrix[bottom][j];
            bottom--;
        }

        if (left <= right) {                         // 向上
            for (int i = bottom; i >= top; i--)
                res[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }
    return res;
}