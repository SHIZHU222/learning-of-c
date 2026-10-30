#define _CRT_SECURE_NO_WARNINGS 
//P1478
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, s;
    int a, b;

    scanf("%d %d", &n, &s);
    scanf("%d %d", &a, &b);

    int reach = a + b;
    int cost[5005];
    int m = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        if (x <= reach) {
            cost[m++] = y;
        }
    }

    qsort(cost, m, sizeof(int), cmp);

    int ans = 0;

    for (int i = 0; i < m; i++) {
        if (cost[i] <= s) {
            s -= cost[i];
            ans++;
        }
        else {
            break;
        }
    }

    printf("%d\n", ans);
    return 0;
}