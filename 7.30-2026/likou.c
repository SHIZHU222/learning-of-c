#define _CRT_SECURE_NO_WARNINGS 
#define min(a, b) ((a) < (b) ? (a) : (b))

int minFallingPathSum(int** matrix, int n, int* colSize) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int best = matrix[i - 1][j];               // 正上方
            if (j > 0)   best = min(best, matrix[i - 1][j - 1]);  // 左上
            if (j < n - 1) best = min(best, matrix[i - 1][j + 1]);  // 右上
            matrix[i][j] += best;
        }
    }
    int ans = matrix[n - 1][0];
    for (int j = 1; j < n; j++)
        ans = min(ans, matrix[n - 1][j]);
    return ans;
}