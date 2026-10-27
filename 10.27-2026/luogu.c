#define _CRT_SECURE_NO_WARNINGS 
//P2678
#include <stdio.h>

static int L, n, m;
static int a[50005];

int check(int d) {
    int cnt = 0, last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] - last < d) cnt++;   /* 移走这块石头 */
        else last = a[i];
    }
    if (L - last < d) cnt++;          /* 终点也要满足 */
    return cnt <= m;
}

int main(void) {
    if (scanf("%d %d %d", &L, &n, &m) != 3) return 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int lo = 1, hi = L, ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) { ans = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}