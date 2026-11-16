#define _CRT_SECURE_NO_WARNINGS 
//P1163
#include <stdio.h>
#include <math.h>

int main(void) {
    long long w0, w, m;
    scanf("%lld %lld %lld", &w0, &w, &m);

    double lo = 0.0, hi = 5.0;      /* 利率区间 [0, 500%]，答案保证 ≤ 300% */

    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2.0;

        double pv;                  /* 还款的现值 */
        if (mid < 1e-12)
            pv = (double)w * m;     /* r → 0 的极限 */
        else
            pv = (double)w * (1.0 - pow(1.0 + mid, -(double)m)) / mid;

        if (pv >= (double)w0)
            lo = mid;               /* 现值偏高 → 利率可以更高 */
        else
            hi = mid;               /* 现值偏低 → 利率必须更低 */
    }

    printf("%.1f\n", lo * 100.0);   /* 转成百分数，保留 1 位小数 */
    return 0;
}