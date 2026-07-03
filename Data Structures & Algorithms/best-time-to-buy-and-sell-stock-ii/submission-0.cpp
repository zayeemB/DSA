class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //------ Memoization ------
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // auto recurse = [&](auto &self, bool holding, int idx)->int{
        //     if(idx == prices.size()){
        //         return 0;
        //     }

        //     int i = holding? 1:0;
        //     if(dp[idx][i] != -1) return dp[idx][i];

        //     int a, b;

        //     if(holding){
        //         a = self(self, !holding, idx+1) + prices[idx];
        //         b = self(self, holding, idx+1);
        //     }
        //     else{
        //         a = self(self, !holding, idx+1) - prices[idx];
        //         b = self(self, holding, idx+1);
        //     }

        //     return dp[idx][i] = max(a, b);
        // };

        // return recurse(recurse, false, 0);

    //------ Tokensization ------ 
        // vector<int> dp(prices.size(), 0);
        // dp[0] = 0;
        // for(int i = 1; i < prices.size(); i++){
        //     dp[i] = max(dp[i-1], dp[i-1] + prices[i]-prices[i-1]);
        // }
        // return dp.back();

    //------ Greedy ------
    int maxProfit = 0;
    for(int i = 1; i < prices.size(); i++){
        maxProfit = max(maxProfit, maxProfit + prices[i] - prices[i-1]);
    }
    return maxProfit;

    }
};