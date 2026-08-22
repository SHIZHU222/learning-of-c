#define _CRT_SECURE_NO_WARNINGS 
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int hold = -prices[0];   /* 持有股票 */
    int sold = 0;            /* 当天卖出（进入冷冻期） */
    int rest = 0;            /* 不持有且不在冷冻期（可买入） */

    for (int i = 1; i < pricesSize; i++) {
        int prevHold = hold, prevSold = sold, prevRest = rest;
        hold = (prevHold > prevRest - prices[i]) ? prevHold : prevRest - prices[i];
        sold = prevHold + prices[i];
        rest = (prevRest > prevSold) ? prevRest : prevSold;
    }

    return sold > rest ? sold : rest;
}