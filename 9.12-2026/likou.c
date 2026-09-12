#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findAnagrams(char* s, char* p, int* returnSize) {
    int sLen = strlen(s), pLen = strlen(p);
    int* res = (int*)malloc(sizeof(int) * (sLen + 1));
    *returnSize = 0;

    if (sLen < pLen) return res;

    int cnt[26] = { 0 };
    for (int i = 0; i < pLen; i++) cnt[p[i] - 'a']++;  // 目标窗口

    int window[26] = { 0 };
    int left = 0;
    for (int right = 0; right < sLen; right++) {
        window[s[right] - 'a']++;
        if (right - left + 1 > pLen) {
            window[s[left] - 'a']--;
            left++;
        }
        if (right - left + 1 == pLen && memcmp(cnt, window, sizeof(cnt)) == 0) {
            res[(*returnSize)++] = left;
        }
    }
    return res;
}