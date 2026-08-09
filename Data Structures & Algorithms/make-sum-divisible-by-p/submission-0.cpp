class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long prefix = 0, sum = 0;
        unordered_map<int,int> map; map[0] = -1;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        int target = sum % p; if(target == 0) return 0;
        int size = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int curr_mod = (prefix % p + p) % p, prev_mod = (curr_mod - target + p) % p;
            if(map.contains(prev_mod)) size = min(size, i - map[prev_mod]);
            map[curr_mod] = i;
        }
        return size == nums.size()? -1: size;
    }
};