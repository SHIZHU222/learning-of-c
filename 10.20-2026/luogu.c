#define _CRT_SECURE_NO_WARNINGS 
//P1024
#include <stdio.h>

double a, b, c, d;

double f(double x) {
    return ((a * x + b) * x + c) * x + d;   // 霍纳法则
}

int main() {
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    int first = 1;
    for (int i = -100; i <= 100; i++) {        // 注意 <= 100
        double x1 = i, x2 = i + 1;
        double f1 = f(x1), f2 = f(x2);

        if (f1 == 0) {                          // 整数根
            if (!first) printf(" ");
            printf("%.2f", x1);
            first = 0;
        }
        else if (f1 * f2 < 0) {               // 区间内异号，有根
            double l = x1, r = x2, mid;
            while (r - l > 1e-6) {
                mid = (l + r) / 2;
                if (f(mid) * f1 <= 0) r = mid;
                else l = mid;
            }
            if (!first) printf(" ");
            printf("%.2f", mid);
            first = 0;
        }
    }

    printf("\n");
    return 0;
}