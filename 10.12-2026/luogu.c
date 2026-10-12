#define _CRT_SECURE_NO_WARNINGS 
//P1044
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long f[20] = { 0 };
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] += f[j] * f[i - 1 - j];

    printf("%lld\n", f[n]);
    return 0;
}