#define _CRT_SECURE_NO_WARNINGS 
//P1028
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int f[1005] = { 0 };
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++)
            f[i] += f[j];
    }

    printf("%d\n", f[n]);
    return 0;
}