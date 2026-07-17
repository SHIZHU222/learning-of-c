#define _CRT_SECURE_NO_WARNINGS 
//P1102
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int n, C;
    scanf("%d%d", &n, &C);
    int a[200005];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), cmp);

    long long ans = 0;
    int l = 0, r = 0;  
    for (int i = 0; i < n; i++) {
        while (l < n && a[l] < a[i] + C) l++;
        while (r < n && a[r] <= a[i] + C) r++;
        ans += r - l;  
    }
    printf("%lld\n", ans);
}