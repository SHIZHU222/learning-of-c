#define _CRT_SECURE_NO_WARNINGS 
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) return 1 / myPow(x, -(long)n);   // 防 INT_MIN 溢出

    double half = myPow(x, n / 2);
    return n % 2 ? half * half * x : half * half;
}
//
double myPow(double x, int n) {
    long N = n;                        // 防 INT_MIN 取负溢出
    if (N < 0) { x = 1 / x; N = -N; }

    double res = 1;
    while (N) {
        if (N & 1) res *= x;           // 二进制位为 1 时乘入
        x *= x;
        N >>= 1;
    }
    return res;
}