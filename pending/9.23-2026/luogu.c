#define _CRT_SECURE_NO_WARNINGS 
//P1308
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static char word[100];
static char art[1000005];   // 用 static 避免大数组放栈上导致溢出

int main(void) {
    fgets(word, sizeof(word), stdin);
    fgets(art, sizeof(art), stdin);

    word[strcspn(word, "\n")] = '\0';
    art[strcspn(art, "\n")] = '\0';

    for (int i = 0; word[i]; i++) word[i] = tolower((unsigned char)word[i]);
    for (int i = 0; art[i]; i++) art[i] = tolower((unsigned char)art[i]);

    int wlen = strlen(word);
    int n = strlen(art);
    int cnt = 0, first = -1;

    for (int i = 0; i < n; ) {
        if (art[i] == ' ') { i++; continue; }
        int start = i;
        while (i < n && art[i] != ' ') i++;
        int len = i - start;
        if (len == wlen && strncmp(art + start, word, wlen) == 0) {
            cnt++;
            if (first == -1) first = start;
        }
    }

    if (cnt == 0) printf("-1\n");
    else printf("%d %d\n", cnt, first);

    return 0;
}