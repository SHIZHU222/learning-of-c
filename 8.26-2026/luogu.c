#include <stdio.h>

int n, k;
int x[25];
int ans;

int isPrime(int a) {
    if (a < 2) return 0;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0) return 0;
    return 1;
}

void dfs(int cnt, int sum, int start) {
    if (cnt == k) {
        if (isPrime(sum)) ans++;
        return;
    }
    for (int i = start; i < n; i++)
        dfs(cnt + 1, sum + x[i], i + 1);
}

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    dfs(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}