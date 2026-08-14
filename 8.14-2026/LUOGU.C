#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    char bestName[9];
    int bestCh = -1, bestMa = -1, bestEn = -1;
    int bestTotal = -1;

    for (int i = 0; i < n; i++) {
        char name[9];
        int ch, ma, en;
        scanf("%s %d %d %d", name, &ch, &ma, &en);
        int total = ch + ma + en;
        if (total > bestTotal) {
            bestTotal = total;
            strcpy(bestName, name);
            bestCh = ch;
            bestMa = ma;
            bestEn = en;
        }
    }

    printf("%s %d %d %d\n", bestName, bestCh, bestMa, bestEn);
    return 0;
}