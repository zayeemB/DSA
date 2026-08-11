class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        unordered_map<int,int> map; map[0] = -1;
        int prefix = 0;
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            int modK = prefix%k;
            if(map.contains(modK)) {if(i - map[modK] >= 2) return true;}
            else map[modK] = i;
        }
        return false;
    }
};