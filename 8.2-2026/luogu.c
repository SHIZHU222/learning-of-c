#define _CRT_SECURE_NO_WARNINGS 
//P1255
#include <stdio.h>
#include <string.h>

int a[5005], b[5005], c[5005];   // 每位存一个十进制数字（低位在前）

int main() {
    int n;
    scanf("%d", &n);

    if (n == 1) { puts("1"); return 0; }
    if (n == 2) { puts("2"); return 0; }

    a[0] = 1;  // f(1) = 1，a[0] 是个位
    b[0] = 2;  // f(2) = 2
    int len = 1;   // 当前位数

    for (int k = 3; k <= n; k++) {
        memset(c, 0, sizeof(c));
        int carry = 0;
        for (int i = 0; i < len; i++) {
            c[i] = a[i] + b[i] + carry;
            carry = c[i] / 10;
            c[i] %= 10;
        }
        if (carry) {
            c[len] = carry;
            len++;
        }
        memcpy(a, b, sizeof(b));      // 滚动：a ← b
        memcpy(b, c, sizeof(c));      //       b ← c
    }

    for (int i = len - 1; i >= 0; i--)   // 高位在前输出
        printf("%d", c[i]);
    return 0;
}