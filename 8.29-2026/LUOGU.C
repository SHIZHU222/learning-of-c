#define _CRT_SECURE_NO_WARNINGS 
//P5730
#include <stdio.h>

// 每个数字的 5 行，每行 3 个字符
const char* digit[10][5] = {
    {"XXX", "X.X", "X.X", "X.X", "XXX"}, // 0
    {"..X", "..X", "..X", "..X", "..X"}, // 1
    {"XXX", "..X", "XXX", "X..", "XXX"}, // 2
    {"XXX", "..X", "XXX", "..X", "XXX"}, // 3
    {"X.X", "X.X", "XXX", "..X", "..X"}, // 4
    {"XXX", "X..", "XXX", "..X", "XXX"}, // 5
    {"XXX", "X..", "XXX", "X.X", "XXX"}, // 6
    {"XXX", "..X", "..X", "..X", "..X"}, // 7
    {"XXX", "X.X", "XXX", "X.X", "XXX"}, // 8
    {"XXX", "X.X", "XXX", "..X", "XXX"}  // 9
};

int main(void) {
    int n;
    char s[105];
    scanf("%d %s", &n, s);

    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(".");          // 数字之间的间隔列
            printf("%s", digit[s[i] - '0'][row]);
        }
        printf("\n");
    }
    return 0;
}