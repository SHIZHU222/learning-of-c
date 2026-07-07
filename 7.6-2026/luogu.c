#include <stdio.h>
#include <stdbool.h>

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    bool tree[10001] = { true };  
    for (int i = 0; i <= l; i++) tree[i] = 1;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        for (int i = u; i <= v; i++)
            tree[i] = 0;   // 移除
    }
    int ans = 0;
    for (int i = 0; i <= l; i++)
        if (tree[i]) ans++;
    printf("%d", ans);
    return 0;
}