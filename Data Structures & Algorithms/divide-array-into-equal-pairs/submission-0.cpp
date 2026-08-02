class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2==1) return false;
        unordered_map<int,int> mp;
        for(auto &n: nums) mp[n]++;
        for(auto &p: mp) if(p.second%2==1) return false;
        return true;
    }
};