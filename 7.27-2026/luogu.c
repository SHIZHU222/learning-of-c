#define _CRT_SECURE_NO_WARNINGS 
//P5743
#include <stdio.h>

int main() {
    int n, ans = 1;
    scanf("%d", &n);
    while (--n)                        // 逆推 n-1 次
        ans = (ans + 1) * 2;
    printf("%d\n", ans);
    return 0;
}