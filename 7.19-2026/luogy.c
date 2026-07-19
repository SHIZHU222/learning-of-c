#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    int n;
    char s[55];
    scanf("%d%s", &n, s);
    for (int i = 0; s[i]; i++)
        s[i] = (s[i] - 'a' + n) % 26 + 'a';
    printf("%s", s);
}