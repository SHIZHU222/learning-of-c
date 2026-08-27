#define _CRT_SECURE_NO_WARNINGS 
//P1923
#include <stdio.h>

int a[5000005];
int n, k;

static int read(void) {
    int x = 0, f = 1;
    int c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * f;
}

void quickselect(int l, int r) {
    if (l >= r) { printf("%d\n", a[l]); return; }
    int i = l, j = r;
    int pivot = a[(l + r) / 2];
    do {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }
    } while (i <= j);
    if (k <= j) quickselect(l, j);
    else if (k >= i) quickselect(i, r);
    else { printf("%d\n", a[j + 1]); }
}

int main(void) {
    n = read(); k = read();
    for (int i = 0; i < n; i++) a[i] = read();
    quickselect(0, n - 1);
    return 0;
}