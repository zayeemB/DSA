class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_subarray = INT_MAX;
        int l = 0, r = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];

            while(sum >= target){
                min_subarray = min(min_subarray, r-l+1);
                sum -= nums[l++];
            }

            r++;
        }
        return min_subarray == INT_MAX? 0: min_subarray;
    }
};