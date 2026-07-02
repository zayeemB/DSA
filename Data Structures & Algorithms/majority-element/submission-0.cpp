class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = 1;
        int max_occur = 1;
        int num = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]){
                curr = 1;
            }
            else{
                curr++;
            }
            if(curr > max_occur){
                num = nums[i];
                max_occur = curr;
            }
        }
        return num;
    }
};