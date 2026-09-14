#define _CRT_SECURE_NO_WARNINGS 
//P2023
#include <stdio.h>

int main() {
    char c;
    int n;
    float f;
    double d;

    scanf("%c", &c);
    scanf("%d", &n);
    scanf("%f", &f);
    scanf("%lf", &d);

    printf("%c %d %f %f\n", c, n, f, d);
    return 0;
}