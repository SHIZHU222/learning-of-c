#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
    long long n, m;
    scanf("%lld %lld", &n, &m);

    long long total = n * (n + 1) / 2 * (m * (m + 1) / 2);

    long long squares = 0;
    long long min = n < m ? n : m;
    for (long long k = 1; k <= min; k++)
        squares += (n - k + 1) * (m - k + 1);

    printf("%lld %lld\n", squares, total - squares);
    return 0;
}