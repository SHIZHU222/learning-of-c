#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

typedef long long ll;

ll A, K, B, M, X;

// 判断 t 天能否砍完
int can(ll t) {
    ll d = t - t / K; // 德米特里工作天数
    ll f = t - t / M; // 费多尔工作天数

    // 避免 A*d 或 B*f 溢出 long long
    // 如果某一个人单独就砍够了，直接返回 1
    if (A > X / d) return 1;
    if (B > X / f) return 1;

    // 此时 A*d <= X，B*f <= X，相加不超过 2e18，long long 安全
    return A * d + B * f >= X;
}

int main() {
    scanf("%lld%lld%lld%lld%lld", &A, &K, &B, &M, &X);

    ll l = 1, r = X; // 答案一定不超过 X 天
    while (l < r) {
        ll mid = l + (r - l) / 2;
        if (can(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%lld\n", l);
    return 0;
}