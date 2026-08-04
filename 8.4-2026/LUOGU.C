#define _CRT_SECURE_NO_WARNINGS 
//1319
#include <stdio.h>

int main() {
    int n, x, cur = 0, bit = 0;      // cur=已填字符数, bit=当前填0还是1
    scanf("%d", &n);

    while (scanf("%d", &x) != EOF) {
        for (int i = 0; i < x; i++) {
            printf("%d", bit);
            if (++cur % n == 0) printf("\n");  // 满 N 个换行
        }
        bit ^= 1;                     // 0/1 交替
    }
    return 0;
}