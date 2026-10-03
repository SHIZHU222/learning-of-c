#define _CRT_SECURE_NO_WARNINGS 
//P3392
#include <stdio.h>

int main(void) {
    int n, m;
    char row[55];
    int w[55] = { 0 }, b[55] = { 0 }, r[55] = { 0 };

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", row);
        for (int j = 0; j < m; j++) {
            if (row[j] != 'W') w[i]++;   // 改成白色要涂的次数
            if (row[j] != 'B') b[i]++;
            if (row[j] != 'R') r[i]++;
        }
    }

    int pw[55] = { 0 }, pb[55] = { 0 }, pr[55] = { 0 };
    for (int i = 0; i < n; i++) {
        pw[i + 1] = pw[i] + w[i];
        pb[i + 1] = pb[i] + b[i];
        pr[i + 1] = pr[i] + r[i];
    }

    int ans = 1 << 30;
    // i = 白色行数, j = 白色+蓝色行数
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            int cost = pw[i] + (pb[j] - pb[i]) + (pr[n] - pr[j]);
            if (cost < ans) ans = cost;
        }
    }

    printf("%d\n", ans);
    return 0;
}