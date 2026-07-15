#define _CRT_SECURE_NO_WARNINGS 
//P1765
#include <stdio.h>
#include <string.h>

int main() {
    char s[205];
    int count = 0;
    int press[26] = {
        1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,  
        1,2,3,4, 1,2,3, 1,2,3,4               
    };

    fgets(s, sizeof(s), stdin);
    for (int i = 0; s[i] != '\0' && s[i] != '\n'; i++) {
        if (s[i] == ' ')
            count += 1;
        else
            count += press[s[i] - 'a'];
    }
    printf("%d\n", count);
    return 0;
}