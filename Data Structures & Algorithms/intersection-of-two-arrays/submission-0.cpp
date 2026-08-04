class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> myset;
        unordered_set<int> res_set;
        for(int n: nums1) myset.insert(n);
        for(int n: nums2) if(myset.contains(n)) res_set.insert(n);
        vector<int> res(res_set.begin(), res_set.end());
        return res;
    }
};