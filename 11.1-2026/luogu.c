#define _CRT_SECURE_NO_WARNINGS 
//P1259
#include <stdio.h>

char s[210];

void move_pair(int a, int b) {
    char x = s[a];
    char y = s[a + 1];

    s[a] = s[b];
    s[a + 1] = s[b + 1];

    s[b] = x;
    s[b + 1] = y;

    printf("%s\n", s + 1);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        s[i] = 'o';
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        s[i] = '*';
    }

    s[2 * n + 1] = '-';
    s[2 * n + 2] = '-';
    s[2 * n + 3] = '\0';

    printf("%s\n", s + 1);

    for (int k = n; k >= 5; k--) {
        move_pair(k, 2 * k + 1);
        move_pair(2 * k - 1, k);
    }

    move_pair(4, 9);
    move_pair(8, 4);
    move_pair(2, 8);
    move_pair(7, 2);
    move_pair(1, 7);

    return 0;
}