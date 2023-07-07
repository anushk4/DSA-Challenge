// comparing adjacent prices and adding to profit
// submission: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/988649184/

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i=1;i<pricesSize;i++){
        if (prices[i]>prices[i-1]){
            profit += prices[i]-prices[i-1]; 
        }
    }
    return profit;
}
