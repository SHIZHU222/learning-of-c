#define _CRT_SECURE_NO_WARNINGS 
int fib(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}
//
int fib(int n) {
    int a = 0, b = 1;
    while (n--) {
        b = a + b;
        a = b - a;
    }
    return a;
}
//
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}