#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int x, a, y, b;
    scanf("%d %d %d %d", &x, &a, &y, &b);
    double z = (double)(y * b - x * a) / (b - a);
    printf("%.2f\n", z);
    return 0;
}