class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = INT_MIN;
        int total_sum = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
            sum = max(nums[i], nums[i]+sum);
            max_sum = max(max_sum, sum);
        }

        sum = 0;
        int min_sum = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            sum = min(nums[i], nums[i]+sum);
            min_sum = min(min_sum, sum);
        }

        if(min_sum == total_sum) return max_sum;
        else return max(max_sum, total_sum-min_sum);
    }
};