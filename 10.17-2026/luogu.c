#define _CRT_SECURE_NO_WARNINGS 
//P3817
#include <stdio.h>

int a[100005];

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    long long ans = 0;

    if (a[0] > x) {
        ans += a[0] - x;
        a[0] = x;
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] + a[i] > x) {
            ans += a[i - 1] + a[i] - x;
            a[i] = x - a[i - 1];
        }
    }

    printf("%lld\n", ans);
    return 0;
}