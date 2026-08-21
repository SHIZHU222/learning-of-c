#define _CRT_SECURE_NO_WARNINGS 
//P2089
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int ans[59049][10];
    int cnt = 0;

    int a[10];
    for (a[0] = 1; a[0] <= 3; a[0]++)
        for (a[1] = 1; a[1] <= 3; a[1]++)
            for (a[2] = 1; a[2] <= 3; a[2]++)
                for (a[3] = 1; a[3] <= 3; a[3]++)
                    for (a[4] = 1; a[4] <= 3; a[4]++)
                        for (a[5] = 1; a[5] <= 3; a[5]++)
                            for (a[6] = 1; a[6] <= 3; a[6]++)
                                for (a[7] = 1; a[7] <= 3; a[7]++)
                                    for (a[8] = 1; a[8] <= 3; a[8]++)
                                        for (a[9] = 1; a[9] <= 3; a[9]++) {
                                            int sum = 0;
                                            for (int k = 0; k < 10; k++) sum += a[k];
                                            if (sum == n) {
                                                for (int k = 0; k < 10; k++)
                                                    ans[cnt][k] = a[k];
                                                cnt++;
                                            }
                                        }

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        for (int k = 0; k < 10; k++)
            printf("%d%c", ans[i][k], k == 9 ? '\n' : ' ');
    }
    return 0;
}