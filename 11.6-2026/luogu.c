#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if (matrixSize == 0 || matrixColSize[0] == 0) return false;

    int m = matrixSize, n = matrixColSize[0];
    int lo = 0, hi = m * n;          /* 虚拟一维区间 [lo, hi) */

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int v = matrix[mid / n][mid % n];   /* 一维下标映射回二维 */

        if (v == target)      return true;
        else if (v < target)  lo = mid + 1;
        else                  hi = mid;
    }
    return false;
}