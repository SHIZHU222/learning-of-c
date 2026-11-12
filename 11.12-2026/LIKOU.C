#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>

char* decodeString(char* s) {
    int n = (int)strlen(s);

    /* 题目保证输出长度不超过 1e5 */
    char* out = (char*)malloc(100005);
    int olen = 0;

    int* stStart = (int*)malloc(sizeof(int) * (n + 1)); /* 每层内容在 out 中的起点 */
    int* stCnt = (int*)malloc(sizeof(int) * (n + 1)); /* 每层的重复次数 */
    int top = 0;

    int i = 0;
    while (i < n) {
        char c = s[i];

        if (c >= '0' && c <= '9') {
            /* 1. 读取可能多位的数字 k */
            int k = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                k = k * 10 + (s[i] - '0');
                i++;
            }
            i++;                       /* 跳过 '[' */

            stStart[top] = olen;       /* 这一层内容从 olen 开始 */
            stCnt[top] = k;
            top++;
        }
        else if (c == ']') {
            /* 2. 弹栈，把 [start, olen) 这段复制 k-1 份 */
            top--;
            int start = stStart[top];
            int k = stCnt[top];
            int len = olen - start;

            for (int t = 1; t < k; t++) {
                memcpy(out + olen, out + start, len);
                olen += len;
            }
            i++;
        }
        else {
            /* 3. 普通字符，直接追加 */
            out[olen++] = c;
            i++;
        }
    }

    out[olen] = '\0';

    free(stStart);
    free(stCnt);
    return out;
}