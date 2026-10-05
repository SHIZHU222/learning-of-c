#define _CRT_SECURE_NO_WARNINGS 
//P1217
#include <stdio.h>

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // 1 位数：5、7（2、3 均 < 5）
    for (int d = 5; d <= 7; d += 2)
        if (d >= a && d <= b) printf("%d\n", d);

    // 特判 11（唯一的偶数位回文质数）
    if (11 >= a && 11 <= b) printf("11\n");

    // 3 位数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            int p = 100 * d1 + 10 * d2 + d1;
            if (p >= a && p <= b && is_prime(p)) printf("%d\n", p);
        }
    }

    // 5 位数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                int p = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
                if (p >= a && p <= b && is_prime(p)) printf("%d\n", p);
            }
        }
    }

    // 7 位数
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; d2++) {
            for (int d3 = 0; d3 <= 9; d3++) {
                for (int d4 = 0; d4 <= 9; d4++) {
                    int p = 1000000 * d1 + 100000 * d2 + 10000 * d3
                        + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
                    if (p >= a && p <= b && is_prime(p)) printf("%d\n", p);
                }
            }
        }
    }

    return 0;
}