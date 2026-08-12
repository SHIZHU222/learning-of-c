#define _CRT_SECURE_NO_WARNINGS 
//P240
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double m, v, r;    // 重量、价值、单位价值
} Coin;

int cmp(const void* a, const void* b) {
    double d = ((Coin*)b)->r - ((Coin*)a)->r;  // 降序
    return d > 0 ? 1 : (d < 0 ? -1 : 0);
}

int main() {
    int N, T;
    scanf("%d%d", &N, &T);

    Coin c[105];
    for (int i = 0; i < N; i++) {
        scanf("%lf%lf", &c[i].m, &c[i].v);
        c[i].r = c[i].v / c[i].m;              // 单位价值
    }

    qsort(c, N, sizeof(Coin), cmp);

    double ans = 0, left = T;
    for (int i = 0; i < N && left > 0; i++) {
        if (c[i].m <= left) {                  // 能全拿
            ans += c[i].v;
            left -= c[i].m;
        }
        else {                               // 只能拿一部分
            ans += c[i].r * left;
            left = 0;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
//换成c++