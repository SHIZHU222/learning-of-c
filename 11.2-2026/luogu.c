#define _CRT_SECURE_NO_WARNINGS 
//P5019
#include <stdio.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long ans = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i) {
        int d;
        scanf("%d", &d);
        if (d > prev) ans += d - prev;
        prev = d;
    }

    printf("%lld\n", ans);
    return 0;
}