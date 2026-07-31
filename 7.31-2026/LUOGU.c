#define _CRT_SECURE_NO_WARNINGS 
//P1152
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a[1005], vis[1005] = { 0 };
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 1; i < n; i++) {
        int d = abs(a[i] - a[i - 1]);
        if (d >= 1 && d <= n - 1)
            vis[d] = 1;                       // 标记出现过的差值
    }

    for (int d = 1; d <= n - 1; d++)
        if (!vis[d]) {                        // 有 1~n-1 中缺失的
            printf("Not jolly");
            return 0;
        }
    printf("Jolly");
    return 0;
}