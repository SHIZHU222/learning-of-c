#define _CRT_SECURE_NO_WARNINGS 
//P1010
#include <stdio.h>

void solve(int n) {
    int first = 1;
    int hi = 0;
    while ((1 << hi) <= n) hi++;
    hi--;

    for (int i = hi; i >= 0; i--) {
        if (n & (1 << i)) {
            if (!first) putchar('+');
            first = 0;
            if (i == 0)
                printf("2(0)");
            else if (i == 1)
                printf("2");
            else {
                printf("2(");
                solve(i);
                putchar(')');
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}