#define _CRT_SECURE_NO_WARNINGS 
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX;   /* 历史最低买入价 */
    int best = 0;             /* 最大利润，默认 0（不能亏） */

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];          /* 更新最低买入价 */
        }
        else if (prices[i] - minPrice > best) {
            best = prices[i] - minPrice;   /* 以今天卖出 */
        }
    }
    return best;
}