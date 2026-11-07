#define _CRT_SECURE_NO_WARNINGS 
//P1182
#include <stdio.h>

#define MAXN 100005

int n, m;
long long a[MAXN];

/* 上限为 x 时，最少能分成几段；判断是否 <= m */
int check(long long x) {
    int cnt = 1;          /* 至少 1 段 */
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= x) {
            sum += a[i];              /* 塞进当前段 */
        }
        else {
            cnt++;                    /* 新开一段 */
            sum = a[i];
            if (cnt > m) return 0;    /* 段数超了，提前退出 */
        }
    }
    return 1;
}

int main(void) {
    scanf("%d %d", &n, &m);

    long long lo = 0, hi = 0;         /* 答案区间 [lo, hi] */
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (a[i] > lo) lo = a[i];     /* 下界：最大单元素 */
        hi += a[i];                   /* 上界：全部合成一段 */
    }

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;     /* 可行，尝试更小 */
        else            lo = mid + 1; /* 不可行，必须更大 */
    }

    printf("%lld\n", lo);
    return 0;
}