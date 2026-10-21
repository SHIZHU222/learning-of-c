#define _CRT_SECURE_NO_WARNINGS 
//P1928
#include <stdio.h>
#include <string.h>

char s[20005];
char out[20005];
int len, outLen;

void expand(int* pos) {
    while (*pos < len && s[*pos] != ']') {
        if (s[*pos] == '[') {
            (*pos)++;                      // 跳过 '['
            int d = 0;
            while (*pos < len && s[*pos] >= '0' && s[*pos] <= '9') {
                d = d * 10 + (s[*pos] - '0');
                (*pos)++;
            }

            int start = outLen;            // 记录本次内容起点
            expand(pos);                   // 递归解析内部（含嵌套）
            int segLen = outLen - start;   // 内部一次内容的长度

            for (int k = 1; k < d; k++)    // 再复制 d-1 次
                for (int j = 0; j < segLen; j++)
                    out[outLen++] = out[start + j];

            (*pos)++;                      // 跳过 ']'
        }
        else {
            out[outLen++] = s[*pos];
            (*pos)++;
        }
    }
}

int main() {
    scanf("%s", s);
    len = strlen(s);
    int pos = 0;
    expand(&pos);
    out[outLen] = '\0';
    printf("%s\n", out);
    return 0;
}