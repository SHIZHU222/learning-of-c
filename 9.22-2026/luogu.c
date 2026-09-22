#define _CRT_SECURE_NO_WARNINGS 
//P1603
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getValue(const char* w) {
    static const char* words[21] = {
        "zero","one","two","three","four","five","six","seven","eight","nine","ten",
        "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
        "eighteen","nineteen","twenty"
    };
    for (int i = 0; i < 21; i++)
        if (strcmp(w, words[i]) == 0) return i;
    if (strcmp(w, "a") == 0)       return 1;
    if (strcmp(w, "another") == 0) return 1;
    if (strcmp(w, "both") == 0)    return 2;
    if (strcmp(w, "first") == 0)   return 1;
    if (strcmp(w, "second") == 0)  return 2;
    if (strcmp(w, "third") == 0)   return 3;
    return -1;
}

int cmp(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main(void) {
    char line[1005];
    fgets(line, sizeof(line), stdin);

    char nums[100][3];
    int cnt = 0;

    char* tok = strtok(line, " \n");
    while (tok != NULL) {
        int len = strlen(tok);
        if (len > 0 && tok[len - 1] == '.') tok[len - 1] = '\0'; // 去掉句号
        int v = getValue(tok);
        if (v >= 0) {
            sprintf(nums[cnt], "%02d", (v * v) % 100);
            cnt++;
        }
        tok = strtok(NULL, " \n");
    }

    if (cnt == 0) {
        printf("0\n");
        return 0;
    }

    qsort(nums, cnt, sizeof(nums[0]), cmp);   // 升序排序

    char result[300] = { 0 };
    for (int i = 0; i < cnt; i++) strcat(result, nums[i]);

    char* p = result;
    while (*p == '0') p++;                     // 去掉前导 0
    printf("%s\n", *p ? p : "0");

    return 0;
}