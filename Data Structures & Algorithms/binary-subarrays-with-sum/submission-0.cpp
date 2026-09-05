class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int count = 0, subArrSum = 0;

        vector<int> zeros(nums.size(), 0);
        for(int i = nums.size()-2; i >= 0; i--){
            if(nums[i+1] == 1){
                zeros[i] = 0;
            }
            else{
                zeros[i] = zeros[i+1]+1;
            }
        }

        while(r < nums.size()){
            subArrSum += nums[r];

            while(l < r+1 && subArrSum >= goal){
                if(subArrSum == goal) count += zeros[r] + 1;
                subArrSum -= nums[l];
                l++;
            }

            r++;
        }

        return count;
    }
};