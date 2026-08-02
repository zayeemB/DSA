class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag = true;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] < nums[i+1]) flag = false;
        }
        if(flag) return true;
        flag = true;
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] > nums[i+1]) flag = false;
        }
        return flag;
    }
};