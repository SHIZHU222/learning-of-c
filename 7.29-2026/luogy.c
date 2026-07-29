#define _CRT_SECURE_NO_WARNINGS 
//P1200
#include <stdio.h>

int main() {
    char a[10], b[10];
    int sa = 1, sb = 1;
    scanf("%s%s", a, b);

    for (int i = 0; a[i]; i++)
        sa = sa * (a[i] - 'A' + 1) % 47;
    for (int i = 0; b[i]; i++)
        sb = sb * (b[i] - 'A' + 1) % 47;

    printf(sa == sb ? "GO" : "STAY");
}