#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

typedef struct {
    int id;
    int academic;   // 学业成绩
    int quality;    // 素质拓展成绩
    double total;   // 综合分数
} Student;

// 相当于“成员函数”，传入结构体返回两科总分
int sum(Student s) {
    return s.academic + s.quality;
}

int isExcellent(Student s) {
    return sum(s) > 140 && s.academic * 7 + s.quality * 3 >= 800;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Student s;
        scanf("%d %d %d", &s.id, &s.academic, &s.quality);
        s.total = s.academic * 0.7 + s.quality * 0.3;
        printf("%s\n", isExcellent(s) ? "Excellent" : "Not excellent");
    }
    return 0;
}