#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p;  // 单价
    int a;  // 可供应量
} Farmer;

/* 按单价升序排序 */
int cmp(const void* x, const void* y) {
    const Farmer* u = (const Farmer*)x;
    const Farmer* v = (const Farmer*)y;
    return u->p - v->p;
}

int main(void) {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Farmer* f = (Farmer*)malloc(sizeof(Farmer) * (m > 0 ? m : 1));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &f[i].p, &f[i].a);
    }

    qsort(f, m, sizeof(Farmer), cmp);

    long long cost = 0;   // 总花费，防止溢出
    int need = n;         // 还需要的牛奶量

    for (int i = 0; i < m && need > 0; i++) {
        int take = (f[i].a < need) ? f[i].a : need;  // 能买多少
        cost += (long long)take * f[i].p;
        need -= take;
    }

    printf("%lld\n", cost);
    free(f);
    return 0;
}