#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void dfs(int n, int open, int close, char* buf, int pos,
    char** res, int* size) {
    if (pos == 2 * n) {
        buf[pos] = '\0';
        res[*size] = (char*)malloc((2 * n + 1) * sizeof(char));
        strcpy(res[*size], buf);
        (*size)++;
        return;
    }
    if (open < n) {
        buf[pos] = '(';
        dfs(n, open + 1, close, buf, pos + 1, res, size);
    }
    if (close < open) {
        buf[pos] = ')';
        dfs(n, open, close + 1, buf, pos + 1, res, size);
    }
}

/* 第 n 个卡特兰数，用于预分配结果数组 */
static long long catalan(int n) {
    long long c = 1;
    for (int i = 0; i < n; ++i)
        c = c * 2 * (2 * i + 1) / (i + 2);
    return c;
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    if (n <= 0) return NULL;

    long long cap = catalan(n);
    char** res = (char**)malloc(cap * sizeof(char*));
    char* buf = (char*)malloc((2 * n + 1) * sizeof(char));

    dfs(n, 0, 0, buf, 0, res, returnSize);

    free(buf);
    return res;
}

/* 测试 */
int main(void) {
    int n = 3, size = 0;
    char** res = generateParenthesis(n, &size);
    for (int i = 0; i < size; ++i) {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);
    return 0;
}