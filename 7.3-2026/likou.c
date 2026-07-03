#include <stdio.h>
#include <string.h>

int value(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default:  return 0;
    }
}

int romanToInt(char* s) {
    int result = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        int cur = value(s[i]);
        // 不是最后一个字符，且当前值小于右边值 → 减法
        if (i + 1 < len && cur < value(s[i + 1]))
            result -= cur;
        else
            result += cur;
    }

    return result;
}

int main() {
    char s[20];
    scanf("%s", s);
    printf("%d\n", romanToInt(s));
    return 0;
}