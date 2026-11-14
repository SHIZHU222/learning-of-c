#define _CRT_SECURE_NO_WARNINGS 
//P2036
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int s[15], b[15];
    for (int i = 0; i < n; i++) scanf("%d %d", &s[i], &b[i]);

    long long ans = 1LL << 60;

    for (int mask = 1; mask < (1 << n); mask++) {   /* 从 1 开始，跳过空集 */
        long long acid = 1, bitter = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                acid *= s[i];
                bitter += b[i];
            }
        }
        long long d = acid - bitter;
        if (d < 0) d = -d;
        if (d < ans) ans = d;
    }

    printf("%lld\n", ans);
    return 0;
}