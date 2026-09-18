#define _CRT_SECURE_NO_WARNINGS 
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize, n = matrixColSize[0];
    int row0 = 0, col0 = 0;   // 记录第一行/第一列是否需要置零

    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) row0 = 1;
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) col0 = 1;

    // 用第一行/第一列作标记
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }

    // 根据标记置零
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    // 处理第一行、第一列
    if (row0) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (col0) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}