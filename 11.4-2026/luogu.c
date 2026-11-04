#define _CRT_SECURE_NO_WARNINGS 
//P1228
#include <stdio.h>

/*
 * (sx, sy) : 当前正方形左上角
 * (hx, hy) : 当前正方形里“缺口”的位置（公主或被上层地毯盖住的格子）
 * len      : 当前正方形边长
 */
void cover(int sx, int sy, int hx, int hy, int len) {
    if (len == 1) return;                 /* 只剩一个格子，结束 */

    int h = len / 2;
    int mx = sx + h - 1, my = sy + h - 1; /* 中心 2x2 块的左上格 */

    if (hx <= mx && hy <= my) {           /* 缺口在左上 */
        printf("%d %d 1\n", sx + h, sy + h);
        cover(sx, sy, hx, hy, h);                       /* 左上，真缺口 */
        cover(sx, sy + h, mx, my + 1, h);               /* 右上，缺口=中心右上 */
        cover(sx + h, sy, mx + 1, my, h);               /* 左下，缺口=中心左下 */
        cover(sx + h, sy + h, mx + 1, my + 1, h);       /* 右下，缺口=中心右下 */
    }
    else if (hx <= mx) {                /* 缺口在右上 */
        printf("%d %d 2\n", sx + h, sy + h - 1);
        cover(sx, sy, mx, my, h);
        cover(sx, sy + h, hx, hy, h);
        cover(sx + h, sy, mx + 1, my, h);
        cover(sx + h, sy + h, mx + 1, my + 1, h);
    }
    else if (hy <= my) {                /* 缺口在左下 */
        printf("%d %d 3\n", sx + h - 1, sy + h);
        cover(sx, sy, mx, my, h);
        cover(sx, sy + h, mx, my + 1, h);
        cover(sx + h, sy, hx, hy, h);
        cover(sx + h, sy + h, mx + 1, my + 1, h);
    }
    else {                              /* 缺口在右下 */
        printf("%d %d 4\n", sx + h - 1, sy + h - 1);
        cover(sx, sy, mx, my, h);
        cover(sx, sy + h, mx, my + 1, h);
        cover(sx + h, sy, mx + 1, my, h);
        cover(sx + h, sy + h, hx, hy, h);
    }
}

int main(void) {
    int k, x, y;
    scanf("%d", &k);
    scanf("%d %d", &x, &y);

    int n = 1 << k;          /* 2^k */
    cover(1, 1, x, y, n);    /* 坐标从 1 开始 */
    return 0;
}