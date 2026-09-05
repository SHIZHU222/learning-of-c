#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
    double f;
    scanf("%lf", &f);
    printf("%.5f\n", 5.0 * (f - 32) / 9.0);
    return 0;
}