class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] >= nums[0]){
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        int n = nums.size();

        r = (l+n-1);
        while(l <= r){
            int mid = l + (r-l)/2;
            if(target > nums[mid%n]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        if(nums[l%n]==target) return l%n;
        return -1;
    }
};