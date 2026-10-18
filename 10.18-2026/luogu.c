#define _CRT_SECURE_NO_WARNINGS 
//P2440
#include <stdio.h>

int n, k;
int L[100005];

int check(long long len) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += L[i] / len;
        if (cnt >= k) return 1;   // 提前返回，避免溢出/无谓计算
    }
    return cnt >= k;
}

int main() {
    scanf("%d %d", &n, &k);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
        if (L[i] > mx) mx = L[i];
    }

    long long lo = 0, hi = mx;
    while (lo < hi) {
        long long mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    printf("%lld\n", lo);
    return 0;
}