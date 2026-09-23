#define _CRT_SECURE_NO_WARNINGS 
//P5461
#include <stdio.h>

int a[1050][1050];   // n<=10，最大 1024x1024，用全局数组避免栈溢出

void solve(int x, int y, int size) {
    if (size == 1) {          // 无法再分，不被赦免
        a[x][y] = 1;
        return;
    }
    int half = size / 2;
    // 左上角 (x..x+half-1, y..y+half-1) 保持 0，不再处理
    solve(x, y + half, half);        // 右上
    solve(x + half, y, half);        // 左下
    solve(x + half, y + half, half); // 右下
}

int main(void) {
    int n;
    scanf("%d", &n);

    int size = 1;
    for (int i = 0; i < n; i++) size *= 2;

    solve(0, 0, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d", a[i][j]);
            if (j != size - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
