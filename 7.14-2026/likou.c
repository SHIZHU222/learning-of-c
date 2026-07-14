#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[101];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[i] = toupper(s[i]);
    }
    printf("%s\n", s);
    return 0;
}