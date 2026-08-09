#define _CRT_SECURE_NO_WARNINGS 
//P1008
#include <stdio.h>

int main() {
    for (int i = 123; i <= 329; i++) {
        int a = i, b = i * 2, c = i * 3;
        int x = a / 100, y = a / 10 % 10, z = a % 10;
        int u = b / 100, v = b / 10 % 10, w = b % 10;
        int p = c / 100, q = c / 10 % 10, r = c % 10;
        // 检查是否包含 1~9 各一次（且不含 0）
        if (x * y * z * u * v * w * p * q * r == 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 &&
            x + y + z + u + v + w + p + q + r == 45)
            printf("%d %d %d\n", a, b, c);
    }
    return 0;
}