#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    char* syms[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

    char* res = (char*)malloc(16);
    res[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(res, syms[i]);
            num -= values[i];
        }
    }
    return res;
}
