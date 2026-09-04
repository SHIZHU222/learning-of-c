#define _CRT_SECURE_NO_WARNINGS 
//P2012
#include <stdio.h>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%.3f%%\n", b * 100.0 / a);
    return 0;
}