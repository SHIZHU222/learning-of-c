#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    // 边界处理：单行或长度小于行数时直接复制
    if (numRows == 1 || len <= numRows) {
        char* res = (char*)malloc(len + 1);
        memcpy(res, s, len + 1);  // 避免 strcpy 的安全警告
        return res;
    }

    char* res = (char*)malloc(len + 1);
    int pos = 0;
    int cycle = 2 * numRows - 2;  // 一个完整周期

    for (int row = 0; row < numRows; row++) {
        for (int i = row; i < len; i += cycle) {
            res[pos++] = s[i];
            // 中间行在同一个周期内还有第二个字符
            if (row > 0 && row < numRows - 1) {
                int second = i + cycle - 2 * row;
                if (second < len) {
                    res[pos++] = s[second];
                }
            }
        }
    }
    res[pos] = '\0';
    return res;
}