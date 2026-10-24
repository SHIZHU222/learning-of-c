#define _CRT_SECURE_NO_WARNINGS 
//P1164
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int dp[10005] = { 0 };
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        int a;
        scanf("%d", &a);
        for (int j = M; j >= a; j--)
            dp[j] += dp[j - a];
    }

    printf("%d\n", dp[M]);
    return 0;
}