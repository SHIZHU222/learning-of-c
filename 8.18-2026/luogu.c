#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    long long x = *(const long long*)a;
    long long y = *(const long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    long long a[100000];
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    qsort(a, n, sizeof(long long), cmp);

    for (int i = 0; i < n; i++)
        printf("%lld%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}