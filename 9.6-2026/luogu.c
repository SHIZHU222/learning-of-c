#define _CRT_SECURE_NO_WARNINGS 
//P2014
#include <stdio.h>
int main() {
    double r;
    scanf("%lf", &r);
    printf("%.4f %.4f %.4f\n", 2 * r, 2 * 3.14159 * r, 3.14159 * r * r);
    return 0;
}
//P2015
#include <stdio.h>
int main() {
    double r1, r2;
    scanf("%lf%lf", &r1, &r2);
    printf("%.2f\n", 1.0 / (1.0 / r1 + 1.0 / r2));
    return 0;
}
