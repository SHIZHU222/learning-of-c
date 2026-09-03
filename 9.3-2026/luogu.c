#define _CRT_SECURE_NO_WARNINGS 
//P2011
#include <cstdio>
int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%.9f\n", (double)a / b);
    return 0;
}