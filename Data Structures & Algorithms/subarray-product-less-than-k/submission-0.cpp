class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // vector<int> onesAhead(nums.size(), 0);

        // for(int i = nums.size()-2; i >= 0; i--){
        //     if(nums[i+1] != 1){
        //         onesAhead[i] = 0;
        //     }
        //     else{
        //         onesAhead[i] = onesAhead[i+1] + 1;
        //     }
        // }

        int l = 0, r = 0;
        int prod = 1, arrCount = 0, contigs = 0;

        while(r < nums.size()){
            prod *= nums[r];
            contigs++;

            while(l < r && prod >= k){
                prod /= nums[l++];
                contigs--;
            }

            if(prod < k) arrCount += contigs;
            r++;
        }

        return arrCount;
    }
};