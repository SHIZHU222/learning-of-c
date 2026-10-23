#define _CRT_SECURE_NO_WARNINGS 
//P2392
#include <stdio.h>

int main() {
    int s[4];
    for (int i = 0; i < 4; i++) scanf("%d", &s[i]);

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int t[25];
        int total = 0;
        for (int j = 0; j < s[i]; j++) {
            scanf("%d", &t[j]);
            total += t[j];
        }

        int dp[601] = { 0 };
        dp[0] = 1;
        for (int j = 0; j < s[i]; j++)
            for (int v = total / 2; v >= t[j]; v--)
                if (dp[v - t[j]]) dp[v] = 1;

        int best = 0;
        for (int v = total / 2; v >= 0; v--)
            if (dp[v]) { best = v; break; }

        ans += total - best;
    }

    printf("%d\n", ans);
    return 0;
}