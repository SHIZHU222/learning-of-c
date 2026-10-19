#define _CRT_SECURE_NO_WARNINGS
//P1464
#include <stdio.h>

long long memo[21][21][21];

long long w(long long a, long long b, long long c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);   // 整体归到 20

    int x = (int)a, y = (int)b, z = (int)c;                  // 此时都在 [1,20]
    if (memo[x][y][z]) return memo[x][y][z];

    if (a < b && b < c)
        return memo[x][y][z] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return memo[x][y][z] = w(a - 1, b, c) + w(a - 1, b - 1, c)
        + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    long long a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) == 3) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}