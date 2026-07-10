class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // int min_subarray = INT_MAX;
        // int l = 0, r = 0;
        // int sum = 0;
        // while(r < nums.size()){
        //     sum += nums[r];

        //     while(sum >= target){
        //         min_subarray = min(min_subarray, r-l+1);
        //         sum -= nums[l++];
        //     }

        //     r++;
        // }
        // return min_subarray == INT_MAX? 0: min_subarray;

        auto maxSubarraySum = [&](int k){
            int sum = 0;
            int min_sum = 0;
            for(int i = 0; i < nums.size(); i++){
                if(i < k){
                    sum += nums[i];
                    min_sum = sum;
                }
                else{
                    sum -= nums[i-k];
                    sum += nums[i];
                    min_sum = max(min_sum, sum);
                }
            }
            return min_sum;
        };

        int l = 0, r = nums.size();
        while(l <= r){
            int mid = l + (r-l)/2;
            if(maxSubarraySum(mid) < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l <= nums.size()? l: 0;
    }
};