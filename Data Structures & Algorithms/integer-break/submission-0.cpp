class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(int k = 1; k < n; k++){
                if(i - k <= 0) break;
                dp[i] = max(dp[i], max(dp[i-k]*k, (i-k)*k));
            }
        }
        return dp[n];
    }
};