#define _CRT_SECURE_NO_WARNINGS 
//P1059
#include <stdio.h>

int main(void) {
    int n;
    int cnt[1001] = { 0 };
    scanf("%d", &n);

    int m = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (cnt[x] == 0) m++;   // 第一次出现，计数
        cnt[x] = 1;
    }

    printf("%d\n", m);
    int first = 1;
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i]) {
            if (!first) printf(" ");
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}