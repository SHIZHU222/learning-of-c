#define _CRT_SECURE_NO_WARNINGS 
//P1598
#include <stdio.h>

int main() {
    int cnt[26] = { 0 }, maxCnt = 0;
    char s[105];

    for (int i = 0; i < 4; i++) {
        fgets(s, sizeof(s), stdin);
        for (int j = 0; s[j]; j++)
            if (s[j] >= 'A' && s[j] <= 'Z') {
                cnt[s[j] - 'A']++;
                if (cnt[s[j] - 'A'] > maxCnt)
                    maxCnt = cnt[s[j] - 'A'];
            }
    }

    for (int h = maxCnt; h > 0; h--) {
        int lastIdx = 25;
        while (lastIdx >= 0 && cnt[lastIdx] < h) lastIdx--;  // 最后一个有 * 的列

        for (int j = 0; j <= lastIdx; j++) {
            if (j > 0) putchar(' ');
            putchar(cnt[j] >= h ? '*' : ' ');
        }
        putchar('\n');
    }

    for (int j = 0; j < 26; j++) {
        if (j > 0) putchar(' ');
        putchar('A' + j);
    }
    putchar('\n');
    return 0;
}