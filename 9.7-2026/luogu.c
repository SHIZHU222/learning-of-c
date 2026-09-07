#define _CRT_SECURE_NO_WARNINGS 
//P2016
#include <stdio.h>
int main() {
    double x;
    scanf("%lf", &x);
    printf("%lld\n", (long long)x);
    return 0;
}
//P2017
#include <stdio.h>
int main() {
    char c;
    scanf("%c", &c);
    printf("%d\n", c);
    return 0;
}
//P2018
#include <stdio.h>
int main() {
    int x;
    scanf("%d", &x);
    printf("%c\n", x);
    return 0;
}