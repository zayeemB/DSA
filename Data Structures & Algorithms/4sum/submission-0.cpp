class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> fourSums;

        for(int h = 0; h < nums.size(); h++){
            if(h != 0 && nums[h] == nums[h-1]) continue;

            long long threeSum_target = target - nums[h];

            for(int i = h+1; i < nums.size(); i++){
                if(i != h+1 && nums[i] == nums[i-1]) continue;

                long long ts_target = threeSum_target - nums[i];

                int l = i+1;
                int r = nums.size()-1;

                while(l < r){
                    if(ts_target > (long long) nums[l]+nums[r]) 
                        l++;
                    else if(ts_target < (long long) nums[l]+nums[r])
                        r--;
                    else{
                        fourSums.push_back({nums[h], nums[i], nums[l], nums[r]});
                        l++;
                        r--;

                        while(l < r && nums[l] == nums[l-1]) l++;
                        while(l < r && nums[r] == nums[r+1]) r--;
                    }
                }
                
            }
        }
        return fourSums;
    }
};