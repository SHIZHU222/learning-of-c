#define _CRT_SECURE_NO_WARNINGS 
#define min(a, b) ((a) < (b) ? (a) : (b))

    int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    // 直接复用最后一行作为 dp 数组
    for (int i = triangleSize - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);

    return triangle[0][0];
}