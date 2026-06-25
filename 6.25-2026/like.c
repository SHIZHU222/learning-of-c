#include <stdio.h>
#include <string.h>

char findTheDifference(char* s, char* t) {
    char result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result ^= s[i];
    }
    for (int i = 0; t[i] != '\0'; i++) {
        result ^= t[i];
    }
    return result;
}

int main() {
    // 测试用例1
    char s1[] = "abcd";
    char t1[] = "abcde";
    printf("s = \"%s\", t = \"%s\" => 被添加的字母: '%c'\n",
        s1, t1, findTheDifference(s1, t1));

    // 测试用例2
    char s2[] = "";
    char t2[] = "y";
    printf("s = \"%s\", t = \"%s\" => 被添加的字母: '%c'\n",
        s2, t2, findTheDifference(s2, t2));

    // 额外测试
    char s3[] = "ae";
    char t3[] = "aea";
    printf("s = \"%s\", t = \"%s\" => 被添加的字母: '%c'\n",
        s3, t3, findTheDifference(s3, t3));

    return 0;
}