#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[505], s2[505];
    scanf("%s", s1);
    scanf("%s", s2);

    int a[505] = { 0 }, b[505] = { 0 }, c[505] = { 0 };
    int la = strlen(s1), lb = strlen(s2);

    for (int i = 0; i < la; i++)
        a[la - 1 - i] = s1[i] - '0';
    for (int i = 0; i < lb; i++)
        b[lb - 1 - i] = s2[i] - '0';

    int lc = la > lb ? la : lb;
    int carry = 0;
    for (int i = 0; i < lc; i++) {
        int s = a[i] + b[i] + carry;
        c[i] = s % 10;
        carry = s / 10;
    }
    if (carry) c[lc++] = carry;

    for (int i = lc - 1; i >= 0; i--)
        printf("%d", c[i]);
    printf("\n");
    return 0;
}