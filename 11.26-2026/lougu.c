#define _CRT_SECURE_NO_WARNINGS 
//P3156
#include <stdio.h>

#define MAXN 2000005

int a[MAXN];

/* 快速读入一个非负整数 */
static int readInt(void) {
    int c = getchar();
    while (c < '0' || c > '9') c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int main(void) {
    int n = readInt();
    int m = readInt();

    for (int i = 1; i <= n; i++) {
        a[i] = readInt();
    }

    for (int i = 0; i < m; i++) {
        int k = readInt();
        printf("%d\n", a[k]);
    }

    return 0;
}