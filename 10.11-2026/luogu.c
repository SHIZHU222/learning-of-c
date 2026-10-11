#define _CRT_SECURE_NO_WARNINGS 
//P3799
#include <stdio.h>
#define MOD 1000000007

int cnt[10005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }

    long long ans = 0;
    for (int L = 2; L <= 10000; L++) {
        if (cnt[L] < 2) continue;

        long long ways = 0;

        // 两根不同长度凑成 L
        for (int i = 1; i * 2 < L; i++) {
            int j = L - i;
            ways += (long long)cnt[i] * cnt[j];
            ways %= MOD;
        }

        // 两根相同长度凑成 L
        if (L % 2 == 0) {
            long long c = cnt[L / 2];
            ways += c * (c - 1) / 2;
            ways %= MOD;
        }

        long long c = cnt[L];
        long long choose2 = c * (c - 1) / 2 % MOD;
        ans = (ans + choose2 % MOD * ways) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}