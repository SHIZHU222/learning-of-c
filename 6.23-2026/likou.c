#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* mergeAlternately(char* word1, char* word2) {
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    char* result = (char*)malloc(len1 + len2 + 1);  // +1 给 '\0'

    int i = 0, j = 0, k = 0;
    while (i < len1 || j < len2) {
        if (i < len1) result[k++] = word1[i++];   // 先取 word1
        if (j < len2) result[k++] = word2[j++];   // 再取 word2
    }
    result[k] = '\0';
    return result;
}