#define _CRT_SECURE_NO_WARNINGS 
//P2028
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a = n / 100;        // 百位
    int b = n / 10 % 10;    // 十位
    int c = n % 10;         // 个位
    printf("%d%d%d\n", c, b, a);
    return 0;
}
//P2030
#include <stdio.h>
#include <math.h>

int main() {
    double xa, ya, xb, yb;
    scanf("%lf %lf %lf %lf", &xa, &ya, &xb, &yb);
    double dx = xa - xb;
    double dy = ya - yb;
    printf("%.3f\n", sqrt(dx * dx + dy * dy));
    return 0;
}