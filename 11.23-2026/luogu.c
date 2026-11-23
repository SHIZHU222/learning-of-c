#define _CRT_SECURE_NO_WARNINGS 
//P1067
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int first = 1;      /* 是否是第一个输出的项 */
    int c;

    for (int e = n; e >= 0; e--) {
        scanf("%d", &c);    /* c 是 x^e 的系数 */
        if (c == 0) continue;

        /* 1. 处理符号 */
        if (first) {
            if (c < 0) putchar('-');
            first = 0;
        }
        else {
            putchar(c > 0 ? '+' : '-');
        }

        /* 2. 处理系数与自变量 */
        int ac = (c < 0) ? -c : c;
        if (e == 0) {
            printf("%d", ac);
        }
        else {
            if (ac != 1) printf("%d", ac);   /* 系数绝对值为 1 时省略 */
            putchar('x');
            if (e > 1) printf("^%d", e);
        }
    }

    putchar('\n');
    return 0;
}