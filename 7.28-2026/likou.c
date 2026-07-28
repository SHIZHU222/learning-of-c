#define _CRT_SECURE_NO_WARNINGS 
//P5744
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[25];
    int age, score;
} Student;

Student train(Student s) {
    s.age++;
    s.score += s.score / 5;           // 提升 20%
    if (s.score > 600) s.score = 600; // 不超过满分
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    Student s;
    while (n--) {
        scanf("%s%d%d", s.name, &s.age, &s.score);
        s = train(s);
        printf("%s %d %d\n", s.name, s.age, s.score);
    }
    return 0;
}
