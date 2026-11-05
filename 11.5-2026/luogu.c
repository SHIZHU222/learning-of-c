#define _CRT_SECURE_NO_WARNINGS 
//P3853
#include <stdio.h>

#define MAXN 100005

int L, N, K;
int pos[MAXN];

/* 判断空旷指数为 t 时是否可行 */
int check(int t) {
    long long need = 0;                 /* 需要的路标总数可能很大 */
    for (int i = 1; i < N; i++) {
        int d = pos[i] - pos[i - 1];
        need += (d - 1) / t;            /* ceil(d/t) - 1 */
        if (need > K) return 0;         /* 提前退出 */
    }
    return need <= K;
}

int main(void) {
    scanf("%d %d %d", &L, &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &pos[i]);

    /* 二分的上界：原本最大的间距（此时不需要新增路标） */
    int lo = 1, hi = 1;
    for (int i = 1; i < N; i++) {
        int d = pos[i] - pos[i - 1];
        if (d > hi) hi = d;
    }

    /* 二分最小的可行 t */
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;       /* 可行，尝试更小 */
        else            lo = mid + 1;   /* 不可行，必须更大 */
    }

    printf("%d\n", lo);
    return 0;
}