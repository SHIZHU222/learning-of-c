#define _CRT_SECURE_NO_WARNINGS 
//P1873
#include <stdio.h>

int h[1000005];
int n;
long long M;

int readInt() {
    int x = 0, c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x;
}

long long readLL() {
    long long x = 0; int c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x;
}

int check(int H) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] > H) sum += h[i] - H;
        if (sum >= M) return 1;      // 提前返回
    }
    return 0;
}

int main() {
    n = readInt();
    M = readLL();

    int mx = 0;
    for (int i = 0; i < n; i++) {
        h[i] = readInt();
        if (h[i] > mx) mx = h[i];
    }

    int lo = 0, hi = mx;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    printf("%d\n", lo);
    return 0;
}