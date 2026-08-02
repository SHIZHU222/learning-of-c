#define _CRT_SECURE_NO_WARNINGS 
#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool dp[301] = { false };                 // n ≤ 300 (LeetCode 约束)
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (!dp[j]) continue;
            for (int k = 0; k < wordDictSize; k++) {
                int len = strlen(wordDict[k]);
                if (j + len == i && strncmp(s + j, wordDict[k], len) == 0) {
                    dp[i] = true;
                    break;
                }
            }
            if (dp[i]) break;
        }
    }
    return dp[n];
}