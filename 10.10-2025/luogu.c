//P4924
#include <stdio.h>

int a[505][505], b[505][505];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = num++;

    while (m--) {
        int x, y, r, z;
        scanf("%d %d %d %d", &x, &y, &r, &z);
        x--; y--;              // 转成 0 基下标
        int k = 2 * r + 1;

        // 1. 取出子矩阵到 b
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                b[i][j] = a[x - r + i][y - r + j];

        // 2. 旋转后写回 a
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++) {
                if (z == 0)                        // 顺时针
                    a[x - r + i][y - r + j] = b[k - 1 - j][i];
                else                               // 逆时针
                    a[x - r + i][y - r + j] = b[j][k - 1 - i];
            }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}