class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%k != 0) return false;

        int subsetSum = total/k;

        int state = 0;
        vector<int> dp((1 << n), -1);

        sort(nums.begin(), nums.end(), greater<>());

        auto recurse = [&](auto &self, int state, int side)->bool{
            if(dp[state] != -1) return dp[state];

            if(state == (1<<n)-1) return true;

            for(int i = 0; i < n; i++){
                if((state & (1<<i)) != 0) continue;
                if(side + nums[i] > subsetSum) continue;

                if(self(self, state | (1 << i), (side + nums[i]) % subsetSum)){
                    return true;
                }
            }
            return dp[state] = false;
        };

        return recurse(recurse, 0, 0);
    }
};