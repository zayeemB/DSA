class Solution {
public:
    int numSquares(int n) {
        int root_n = sqrt(n);

        vector<int> squares;
        for(int i = 1; i <= root_n; i++){
            squares.push_back(i*i);
        }

        vector<unsigned int> dp(n+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= n; i++){
            for(auto sq: squares){
                if(i >= sq){
                    dp[i] = min(dp[i-sq] + 1, dp[i]);
                }
            }
        }
        return dp[n];
    }
};