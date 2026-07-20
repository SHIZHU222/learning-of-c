#define _CRT_SECURE_NO_WARNINGS 
int climbStairs(int n) {
    int a = 1, b = 2;
    if (n == 1) return a;
    for (int i = 3; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
//
int climbStairs(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        b = a + b;
        a = b - a;
    }
    return b;
}