#define _CRT_SECURE_NO_WARNINGS 
//P1003
#include <stdio.h>

int main() {
    int n, a[10005], b[10005], g[10005], k[10005];
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &a[i], &b[i], &g[i], &k[i]);

    int x, y;
    scanf("%d%d", &x, &y);

    for (int i = n; i >= 1; i--) {
        if (x >= a[i] && x <= a[i] + g[i] &&
            y >= b[i] && y <= b[i] + k[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
