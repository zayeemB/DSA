class Solution {
public:
    bool canFormPairs(const vector<int>& nums, int p, int max_diff) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            // If the adjacent pair is within the allowed difference
            if (nums[i + 1] - nums[i] <= max_diff) {
                count++;
                i++; 
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back()-nums[0];
        while(l < r){
            int mid = l + (r-l)/2;
            if(canFormPairs(nums, p, mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};