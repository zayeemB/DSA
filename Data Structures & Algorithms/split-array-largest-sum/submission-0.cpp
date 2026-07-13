class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int max_num = INT_MIN;
        for(auto &num: nums){
            sum += num;
            max_num = max(max_num, num);
        }

        if(sum == 0) return 0;
        
        auto subArrays = [&](int capacity){
            int n = 0, sum = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] + sum > capacity){
                    n++;
                    sum = 0;
                }
                sum += nums[i]; 

                if(i == nums.size()-1)
                    n++;
            }
            return n;
        };
 
        int l = 1, r = sum;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(mid < max_num || subArrays(mid) > k)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};