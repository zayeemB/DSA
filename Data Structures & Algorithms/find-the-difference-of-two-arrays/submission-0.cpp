class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(auto &n: nums1) set1.insert(n);
        for(auto &n: nums2) set2.insert(n);
        vector<int> a, b;
        for(auto n: set1) if(!set2.contains(n)){a.push_back(n);}
        for(auto n: set2) if(!set1.contains(n)){b.push_back(n);}
        return {a,b};
    }
};