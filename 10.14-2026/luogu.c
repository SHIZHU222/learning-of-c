#define _CRT_SECURE_NO_WARNINGS 
//P2249
#include <stdio.h>

int a[1000005];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    while (m--) {
        int q;
        scanf("%d", &q);
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= q) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if (ans == -1 || a[ans] != q)
            printf("-1 ");
        else
            printf("%d ", ans + 1);
    }
    return 0;
}