class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        long long count = 0;
        const int mod = 1e9 + 7;
        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                count = (count + pow2[r - l]) % mod;
                l++;
            }
            else{
                r--;
            }
        }
        return count;
    }
};