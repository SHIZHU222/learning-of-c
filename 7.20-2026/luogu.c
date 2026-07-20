#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);

    double a = hypot(x1 - x2, y1 - y2);
    double b = hypot(x2 - x3, y2 - y3);
    double c = hypot(x3 - x1, y3 - y1);

    printf("%.2f\n", a + b + c);
    return 0;
}