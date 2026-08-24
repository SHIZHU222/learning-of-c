#define _CRT_SECURE_NO_WARNINGS
int maxProfit(int* prices, int pricesSize, int fee) {
    int hold = -prices[0];   /* 持有股票的最大利润 */
    int cash = 0;            /* 不持有股票的最大利润 */

    for (int i = 1; i < pricesSize; i++) {
        int prevHold = hold;
        hold = (hold > cash - prices[i]) ? hold : cash - prices[i];
        cash = (cash > prevHold + prices[i] - fee) ? cash : prevHold + prices[i] - fee;
    }
    return cash;
}