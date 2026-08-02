class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prodA = nums[nums.size()-1]*nums[nums.size()-2];
        return (int) (prodA - (long long)nums[0]*nums[1]);
    }
};