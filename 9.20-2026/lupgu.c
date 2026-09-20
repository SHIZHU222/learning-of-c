#define _CRT_SECURE_NO_WARNINGS 
//P
#include <stdio.h>

int main(void) {
    int s1, s2, s3;
    scanf("%d %d %d", &s1, &s2, &s3);

    int cnt[100] = { 0 };
    for (int i = 1; i <= s1; i++)
        for (int j = 1; j <= s2; j++)
            for (int k = 1; k <= s3; k++)
                cnt[i + j + k]++;

    int best = 3, bestCnt = cnt[3];
    for (int s = 4; s <= s1 + s2 + s3; s++)
        if (cnt[s] > bestCnt) {   // 严格大于，保证相同次数取最小和
            bestCnt = cnt[s];
            best = s;
        }

    printf("%d\n", best);
    return 0;
}