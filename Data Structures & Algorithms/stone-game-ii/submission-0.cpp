class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        vector<int> suffix = piles;
        for(int i = n - 2; i >= 0; i--) {
            suffix[i] += suffix[i + 1];
        }

        auto recurse = [&](auto &self, int i, int M) -> int {
            if (i == n) return 0;
            if (dp[i][M] != -1) return dp[i][M];

            int maxScore = 0;
            for (int x = 1; x <= 2 * M && i + x <= n; x++) {
                int next_M = max(M, x);
                
                maxScore = max(maxScore, suffix[i] - self(self, i + x, next_M));
            }

            return dp[i][M] = maxScore;
        };
        
        return recurse(recurse, 0, 1);
    }
};