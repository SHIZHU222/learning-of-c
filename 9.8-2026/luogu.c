#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>

int main() {
    int a;
    bool b;
    scanf("%d", &a);
    b = a;
    a = b;
    printf("%d\n", a);
    return 0;
}