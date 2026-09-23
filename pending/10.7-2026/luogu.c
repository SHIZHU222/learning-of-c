#define _CRT_SECURE_NO_WARNINGS 
//P3799
#include <stdio.h>

#define MOD 1000000007LL

int main() {
    int n;
    scanf("%d", &n);

    long long cnt[5001] = { 0 };
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
        if (x > maxLen) maxLen = x;
    }

    // C2[v] = C(cnt[v], 2)
    long long C2[5001] = { 0 };
    for (int v = 1; v <= 5000; v++)
        C2[v] = cnt[v] * (cnt[v] - 1) / 2 % MOD;

    long long ans = 0;
    for (int L = 2; L <= maxLen; L++) {
        if (C2[L] == 0) continue;

        long long pairWays = 0;
        for (int x = 1; x * 2 < L; x++)                 // x < L-x
            pairWays = (pairWays + cnt[x] * cnt[L - x]) % MOD;
        if (L % 2 == 0)                                  // x == L-x
            pairWays = (pairWays + C2[L / 2]) % MOD;

        ans = (ans + C2[L] * pairWays) % MOD;
    }

    printf("%lld\n", ans);
    return 0;
}