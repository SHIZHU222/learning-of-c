#define _CRT_SECURE_NO_WARNINGS 
//P2415
#include <stdio.h>

int main(void) {
    long long sum = 0;   // 元素和，最大 30*1000 = 30000
    int x, n = 0;

    while (scanf("%d", &x) != EOF) {
        sum += x;
        n++;
    }

    // sum * 2^(n-1)，用左移实现
    printf("%lld\n", sum << (n - 1));
    return 0;
}