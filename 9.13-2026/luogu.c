#define _CRT_SECURE_NO_WARNINGS 
//P1706
#include <stdio.h>
int n;
int a[10];
int used[10];

void dfs(int pos) {
    if (pos > n) {           // 填满了，输出
        for (int i = 1; i <= n; i++) printf("%5d", a[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {      // 数字 i 还没用过
            used[i] = 1;     // 标记：用了
            a[pos] = i;      // 放到第 pos 位
            dfs(pos + 1);    // 递归填下一位
            used[i] = 0;     // 回溯：撤销标记，换别的数字
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}