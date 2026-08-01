class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1));

        auto recurse = [&](auto &self, int i, int j){
            if(dp[i][j] != -1) return dp[i][j];
            if(i == j) return piles[i];
            return dp[i][j] = max(piles[i] - self(self, i+1, j), piles[j]-self(self, i,j-1));
        };

        return recurse(recurse, 0, piles.size()-1) > 0;
    }
};