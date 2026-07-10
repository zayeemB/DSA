class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int max_profit = INT_MIN;
        for(auto price: prices){
            buy = min(buy, price);
            if(buy < price)
                max_profit = max(max_profit, price-buy);
        }
        return max_profit==INT_MIN? 0: max_profit;
    }
};