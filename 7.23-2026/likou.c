#define min(a, b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize) {
    int a = 0, b = 0;          // dp[i-2], dp[i-1]
    for (int i = 2; i <= costSize; i++) {
        int c = min(b + cost[i - 1], a + cost[i - 2]);
        a = b;
        b = c;
    }
    return b;
}