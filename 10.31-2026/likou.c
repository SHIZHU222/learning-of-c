#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>

static const char* mapping[10] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

static void dfs(const char* digits, int len, int pos, char* current,
    char** result, int* returnSize) {
    if (pos == len) {
        int index = (*returnSize)++;
        result[index] = (char*)malloc(sizeof(char) * (len + 1));
        memcpy(result[index], current, len + 1);
        return;
    }

    const char* letters = mapping[digits[pos] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) {
        current[pos] = letters[i];
        dfs(digits, len, pos + 1, current, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    int len = (int)strlen(digits);
    *returnSize = 0;

    if (len == 0) {
        return NULL;
    }

    int total = 1;
    for (int i = 0; i < len; i++) {
        total *= (int)strlen(mapping[digits[i] - '0']);
    }

    char** result = (char**)malloc(sizeof(char*) * total);
    char* current = (char*)malloc(sizeof(char) * (len + 1));
    current[len] = '\0';

    dfs(digits, len, 0, current, result, returnSize);

    free(current);
    return result;
}