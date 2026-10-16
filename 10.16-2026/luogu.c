#define _CRT_SECURE_NO_WARNINGS 
//P1678
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x, const void* y) {
    return *(int*)x - *(int*)y;
}

int a[100005];

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    qsort(a, m, sizeof(int), cmp);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);

        int l = 0, r = m - 1, p = m;   // p = 第一个 >= b 的位置
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= b) {
                p = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        int best = 1 << 30;
        if (p < m) {
            int d = a[p] - b;
            if (d < best) best = d;
        }
        if (p - 1 >= 0) {
            int d = b - a[p - 1];
            if (d < best) best = d;
        }
        sum += best;
    }

    printf("%lld\n", sum);
    return 0;
}