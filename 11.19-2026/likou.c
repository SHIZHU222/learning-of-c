#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>

int* partitionLabels(char* s, int* returnSize) {
    int n = (int)strlen(s);

    int last[26];
    for (int i = 0; i < 26; i++) last[i] = -1;

    for (int i = 0; i < n; i++)
        last[s[i] - 'a'] = i;          /* 每个字母最后出现的位置 */

    int* res = (int*)malloc(n * sizeof(int));
    int cnt = 0;
    int start = 0, end = 0;

    for (int i = 0; i < n; i++) {
        if (last[s[i] - 'a'] > end)
            end = last[s[i] - 'a'];    /* 扩展当前片段右边界 */

        if (i == end) {                /* 当前片段可以切分 */
            res[cnt++] = end - start + 1;
            start = end + 1;
        }
    }

    *returnSize = cnt;
    return res;
}