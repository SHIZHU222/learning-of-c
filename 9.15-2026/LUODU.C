#define _CRT_SECURE_NO_WARNINGS 
//P2024
#include <stdio.h>

int main() {
    double d;
    scanf("%lf", &d);
    printf("%f\n", d);
    printf("%.5f\n", d);
    printf("%e\n", d);
    printf("%g\n", d);
    return 0;
}
//P2026
#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf%lf", &a, &b);
    double k = (long long)(a / b);   // k 是整数
    double r = a - k * b;            // r = a - k*b
    printf("%.4f\n", r);
    return 0;
}
//P2027
#include <stdio.h>

int main() {
    int r;
    scanf("%d", &r);
    double v = 4.0 / 3.0 * 3.14 * r * r * r;
    printf("%.5f\n", v);
    return 0;
}