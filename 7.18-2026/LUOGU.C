#define _CRT_SECURE_NO_WARNINGS 
//P1321
#include <stdio.h>

int main() {
    char s[260];
    int boy = 0, girl = 0;
    scanf("%s", s);

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'b' || s[i] == 'o' || s[i] == 'y') {
            boy++;
            if (s[i] == 'b' && s[i + 1] == 'o') i++;
            if (s[i] == 'o' && s[i + 1] == 'y') i++;
        }
        else if (s[i] == 'g' || s[i] == 'i' || s[i] == 'r' || s[i] == 'l') {
            girl++;
            if (s[i] == 'g' && s[i + 1] == 'i') i++;
            if (s[i] == 'i' && s[i + 1] == 'r') i++;
            if (s[i] == 'r' && s[i + 1] == 'l') i++;
        }
    }
    printf("%d\n%d", boy, girl);
}