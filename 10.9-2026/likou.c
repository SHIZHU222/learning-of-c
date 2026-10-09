#define _CRT_SECURE_NO_WARNINGS 
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = 0, col = matrixColSize[0] - 1;   // 从右上角开始

    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            col--;                              // 当前值偏大，往左
        else
            row++;                              // 当前值偏小，往下
    }
    return false;
}