#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 17          /* s 长度 <= 16 */

static int n;
static char* S;
static bool pal[MAXN][MAXN];

static char* path[MAXN]; /* 当前方案的各个子串 */
static int plen;

static char*** res;      /* 结果：二维字符串数组 */
static int* colSizes;    /* 每行的长度 */
static int size, cap;

/* 把当前 path 深拷贝一份存进结果 */
static void save(void) {
    if (size == cap) {
        cap = cap ? cap * 2 : 16;
        res = (char***)realloc(res, cap * sizeof(char**));
        colSizes = (int*)realloc(colSizes, cap * sizeof(int));
    }
    char** row = (char**)malloc(plen * sizeof(char*));
    for (int i = 0; i < plen; i++) {
        int len = (int)strlen(path[i]);
        row[i] = (char*)malloc(len + 1);
        memcpy(row[i], path[i], len + 1);   /* 含 '\0' */
    }
    res[size] = row;
    colSizes[size] = plen;
    size++;
}

static void dfs(int start) {
    if (start == n) {          /* 切完了 */
        save();
        return;
    }
    for (int end = start; end < n; end++) {
        if (!pal[start][end]) continue;     /* 剪枝：不是回文就跳过 */

        int len = end - start + 1;
        char* sub = (char*)malloc(len + 1);
        memcpy(sub, S + start, len);
        sub[len] = '\0';

        path[plen++] = sub;
        dfs(end + 1);                       /* 递归切剩余部分 */
        plen--;                             /* 回溯 */
        free(sub);
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    n = (int)strlen(s);
    S = s;

    /* 1. 预处理回文区间 */
    memset(pal, 0, sizeof(pal));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1]))
                pal[i][j] = true;
        }
    }

    /* 2. 回溯搜所有方案 */
    res = NULL;
    colSizes = NULL;
    size = cap = 0;
    plen = 0;
    dfs(0);

    *returnSize = size;
    *returnColumnSizes = colSizes;
    return res;
}