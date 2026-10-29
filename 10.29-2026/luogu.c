#define _CRT_SECURE_NO_WARNINGS 
//P1990
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("1\n");
        return 0;
    }
    if (n == 2) {
        printf("2\n");
        return 0;
    }
    if (n == 3) {
        printf("5\n");
        return 0;
    }

    int f1 = 1;  // f[1]
    int f2 = 2;  // f[2]
    int f3 = 5;  // f[3]
    int fn;

    for (int i = 4; i <= n; i++) {
        fn = (2 * f3 + f1) % 10000;
        f1 = f2;
        f2 = f3;
        f3 = fn;
    }

    printf("%d\n", f3);
    return 0;
}