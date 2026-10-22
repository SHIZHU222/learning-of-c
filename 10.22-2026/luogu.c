#define _CRT_SECURE_NO_WARNINGS 
//P2437
#include <stdio.h>
#include <string.h>

#define MAXN 1005

// 大数加法，数字逆序存储（个位在前）
void bigAdd(int* x, int lx, int* y, int ly, int* z, int* lz) {
    int carry = 0, i = 0;
    int max = lx > ly ? lx : ly;
    for (i = 0; i < max; i++) {
        int s = carry + (i < lx ? x[i] : 0) + (i < ly ? y[i] : 0);
        z[i] = s % 10;
        carry = s / 10;
    }
    if (carry) z[i++] = carry;
    *lz = i;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int k = n - m + 1;                 // 需要第 k 个斐波那契数

    if (k <= 2) {
        printf("1\n");
        return 0;
    }

    int a[MAXN] = { 1 }, b[MAXN] = { 1 };  // a = fib[i-1], b = fib[i]
    int la = 1, lb = 1;
    int c[MAXN], lc;

    for (int i = 3; i <= k; i++) {
        bigAdd(a, la, b, lb, c, &lc);
        memcpy(a, b, sizeof(int) * lb);
        la = lb;
        memcpy(b, c, sizeof(int) * lc);
        lb = lc;
    }

    for (int i = lb - 1; i >= 0; i--)
        printf("%d", b[i]);
    printf("\n");
    return 0;
}