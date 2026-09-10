#define _CRT_SECURE_NO_WARNINGS 
//P2020
#include <stdio.h>

int main(void) {
    int a[6];
    for (int i = 1; i <= 5; i++) scanf("%d", &a[i]);

    int eaten = 0;
    for (int i = 1; i <= 5; i++) {
        int cur = a[i];
        int give = cur / 3;
        eaten += cur % 3;

        int left = i - 1, right = i + 1;
        if (left < 1) left = 5;
        if (right > 5) right = 1;

        a[i] = give;          // 自己留一份
        a[left] += give;      // 给左边一份
        a[right] += give;     // 给右边一份
    }

    for (int i = 1; i <= 5; i++) {
        if (i > 1) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", eaten);
    return 0;
}
//P2021
#include <stdio.h>

int main(void) {
    float x;
    scanf("%f", &x);
    printf("%.3f\n", x);
    return 0;
}
//P2022
#include <stdio.h>

int main(void) {
    double x;
    scanf("%lf", &x);
    printf("%.12f\n", x);
    return 0;
}