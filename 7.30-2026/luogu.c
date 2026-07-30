#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int n, k, sum;
    scanf("%d%d", &n, &k);
    sum = n;                              // 初始 n 根直接抽
    while (n >= k) {
        int c = n / k;                    // 能换 c 根新烟
        sum += c;
        n = n % k + c;                    // 剩余烟蒂 + 新烟蒂
    }
    printf("%d\n", sum);
    return 0;
}