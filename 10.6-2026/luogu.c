#define _CRT_SECURE_NO_WARNINGS 
//P1149
#include <stdio.h>

int main() {
    int cost[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

    int n;
    scanf("%d", &n);

    // 预计算 0..2000 每个数需要的火柴数（A+B 最大到 2000）
    int f[2001];
    for (int i = 0; i <= 2000; i++) {
        if (i == 0) {
            f[i] = cost[0];          // 数字 0 需要 6 根
        }
        else {
            int t = i, sum = 0;
            while (t) {
                sum += cost[t % 10];
                t /= 10;
            }
            f[i] = sum;
        }
    }

    int cnt = 0;
    for (int a = 0; a <= 1000; a++)
        for (int b = 0; b <= 1000; b++)
            if (f[a] + f[b] + f[a + b] + 4 == n)
                cnt++;

    printf("%d\n", cnt);
    return 0;
}
