#define _CRT_SECURE_NO_WARNINGS 
//P5741
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[9];
    int ch, ma, en;
    int sum;
} Student;

int main(void) {
    int n;
    Student s[1005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", s[i].name, &s[i].ch, &s[i].ma, &s[i].en);
        s[i].sum = s[i].ch + s[i].ma + s[i].en;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(s[i].ch - s[j].ch) <= 5 &&
                abs(s[i].ma - s[j].ma) <= 5 &&
                abs(s[i].en - s[j].en) <= 5 &&
                abs(s[i].sum - s[j].sum) <= 10)
                printf("%s %s\n", s[i].name, s[j].name);
        }
    }
    return 0;
}