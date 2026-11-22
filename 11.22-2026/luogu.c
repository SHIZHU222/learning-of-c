#define _CRT_SECURE_NO_WARNINGS 
//P2615
#include <stdio.h>

int a[45][45];

int main(void) {
    int n;
    scanf("%d", &n);

    int r = 0, c = n / 2;      /* 1 放在第一行中间（0 基） */
    a[r][c] = 1;

    for (int k = 2; k <= n * n; k++) {
        if (r == 0 && c != n - 1) {
            /* 规则 1：第一行但不在最后一列 → 最后一行，右一列 */
            r = n - 1;
            c = c + 1;
        }
        else if (c == n - 1 && r != 0) {
            /* 规则 2：最后一列但不在第一行 → 第一列，上一行 */
            r = r - 1;
            c = 0;
        }
        else if (r == 0 && c == n - 1) {
            /* 规则 3：第一行最后一列 → 正下方 */
            r = r + 1;
        }
        else {
            /* 规则 4：既不在第一行也不在最后一列 */
            if (a[r - 1][c + 1] == 0) {
                r = r - 1;     /* 右上方为空 → 填右上方 */
                c = c + 1;
            }
            else {
                r = r + 1;     /* 右上方已有数 → 填正下方 */
            }
        }
        a[r][c] = k;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}