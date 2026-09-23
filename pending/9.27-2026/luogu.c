#define _CRT_SECURE_NO_WARNINGS 
//P2676
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;   // 从大到小
}

int main(void) {
    int n, b;
    int h[20000];
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);

    qsort(h, n, sizeof(int), cmp);

    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        sum += h[i];
        cnt++;
        if (sum >= b) break;
    }

    printf("%d\n", cnt);
    return 0;
}