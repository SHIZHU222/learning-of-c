#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[40005];
    char line[205];
    int total = 0, n = 0;

    while (fgets(line, sizeof(line), stdin)) {
        line[strcspn(line, "\r\n")] = '\0';
        int len = (int)strlen(line);
        if (len == 0) continue;
        if (n == 0) n = len;
        for (int j = 0; j < len; j++)
            s[total++] = line[j];
    }

    printf("%d", n);

    char cur = '0';
    int cnt = 0;
    for (int i = 0; i < total; i++) {
        if (s[i] == cur) {
            cnt++;
        }
        else {
            printf(" %d", cnt);
            cnt = 1;
            cur = s[i];
        }
    }
    printf(" %d\n", cnt);

    return 0;
}