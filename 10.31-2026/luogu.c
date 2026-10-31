#define _CRT_SECURE_NO_WARNINGS 
//P3612
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[35];
    long long n;

    scanf("%s %lld", s, &n);

    long long len = (long long)strlen(s);

    while (len < n) {
        len <<= 1;
    }

    long long base = (long long)strlen(s);

    while (len > base) {
        long long half = len >> 1;

        if (n == half + 1) {
            n = half;
        }
        else if (n > half + 1) {
            n -= half + 1;
        }

        len = half;
    }

    printf("%c\n", s[n - 1]);
    return 0;
}