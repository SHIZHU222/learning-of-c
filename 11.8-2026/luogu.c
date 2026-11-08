#define _CRT_SECURE_NO_WARNINGS 
//P4995
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* x, const void* y) {
    return *(const int*)x - *(const int*)y;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int h[305];
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    qsort(h, n, sizeof(int), cmp);          /* 高度升序 */

    /* 第一跳：地面 0 -> 最高石头 */
    long long ans = (long long)h[n - 1] * h[n - 1];

    int l = 0, r = n - 2;   /* 还没跳过的石头区间 [l, r] */
    int cur = n - 1;        /* 当前所在石头的下标 */
    int goMin = 1;          /* 下一步去最小值？ */

    while (l <= r) {
        int nxt = goMin ? l++ : r--;        /* 交替取最小 / 最大 */
        long long d = (long long)h[cur] - h[nxt];
        ans += d * d;
        cur = nxt;
        goMin ^= 1;                         /* 切换方向 */
    }

    printf("%lld\n", ans);
    return 0;
}