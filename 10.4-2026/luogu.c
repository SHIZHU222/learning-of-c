#define _CRT_SECURE_NO_WARNINGS 
//P3654
#include <stdio.h>

int main(void) {
    int R, C, K;
    scanf("%d %d %d", &R, &C, &K);

    char grid[105][105];
    for (int i = 0; i < R; i++) scanf("%s", grid[i]);

    if (K == 1) {   // 1×1 时横竖是同一种，避免重复计数
        int cnt = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (grid[i][j] == '.') cnt++;
        printf("%d\n", cnt);
        return 0;
    }

    long long ans = 0;

    // 横向
    for (int i = 0; i < R; i++) {
        int cnt = 0;
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                cnt++;
                if (cnt >= K) ans++;
            }
            else cnt = 0;
        }
    }

    // 纵向
    for (int j = 0; j < C; j++) {
        int cnt = 0;
        for (int i = 0; i < R; i++) {
            if (grid[i][j] == '.') {
                cnt++;
                if (cnt >= K) ans++;
            }
            else cnt = 0;
        }
    }

    printf("%lld\n", ans);
    return 0;
}