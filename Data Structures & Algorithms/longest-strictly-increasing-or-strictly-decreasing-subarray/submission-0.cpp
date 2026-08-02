class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        int curr = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]) curr = 1;
            else curr++;
            res = max(res, curr);
        }
        curr = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= nums[i-1]) curr = 1;
            else curr++;
            res = max(res, curr);
        }
        return res;
    }
};