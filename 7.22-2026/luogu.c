#include <stdio.h>

int f(int n) {
    return n <= 1 ? 1 : n * f(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
}