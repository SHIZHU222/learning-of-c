#define _CRT_SECURE_NO_WARNINGS 
//P1328
#include <stdio.h>

int main(void) {
    int n, na, nb;
    scanf("%d %d %d", &n, &na, &nb);

    int a[205], b[205];
    for (int i = 0; i < na; i++) scanf("%d", &a[i]);
    for (int i = 0; i < nb; i++) scanf("%d", &b[i]);

    /* beat[x][y] == 1 表示 x 胜 y */
    int beat[5][5] = {
        {0, 0, 1, 1, 0},   /* 剪刀 */
        {1, 0, 0, 1, 0},   /* 石头 */
        {0, 1, 0, 0, 1},   /* 布   */
        {0, 0, 1, 0, 1},   /* 蜥蜴人 */
        {1, 1, 0, 0, 0}    /* 斯波克 */
    };

    int scoreA = 0, scoreB = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i % na];
        int y = b[i % nb];
        scoreA += beat[x][y];
        scoreB += beat[y][x];      /* 同一张表反着查即可 */
    }

    printf("%d %d\n", scoreA, scoreB);
    return 0;
}