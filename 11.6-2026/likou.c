#define _CRT_SECURE_NO_WARNINGS 
//P1094
#include <stdio.h>
#include <stdlib.h>

#define MAXN 30005

int p[MAXN];

int cmp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

int main(void) {
    int w, n;
    scanf("%d", &w);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);

    qsort(p, n, sizeof(int), cmp);   /* 价格升序 */

    int i = 0, j = n - 1, ans = 0;

    while (i <= j) {
        if (i < j && p[i] + p[j] <= w)
            i++;          /* 最便宜的也被最贵的一起带走 */
        /* 否则最贵的单独一组 */
        j--;
        ans++;
    }

    printf("%d\n", ans);
    return 0;
}