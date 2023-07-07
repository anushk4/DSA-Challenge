// submission: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/987175108/

int maxProfit(int* prices, int pricesSize){
    int min_price=prices[0];
    int max_profit=0;
    for (int i=0;i<pricesSize;i++){
        if (prices[i]<min_price){
            min_price=prices[i];
        }else{
            int profit=prices[i]-min_price;
            if (profit>max_profit){
                max_profit=profit;
            }
        }
    }
    return max_profit;
}
