#define _CRT_SECURE_NO_WARNINGS 
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int n = matrixSize;

    // 1. 转置（只处理对角线右上半部分，避免重复交换）
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // 2. 每一行左右翻转
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = tmp;
        }
    }
}