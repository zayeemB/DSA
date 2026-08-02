class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums2.size(); i++)
            mp[nums2[i]] = i;
        
        vector<int> ans;
        bool found = false;
        for(auto &n: nums1){
            found = false;
            for(int idx = mp[n]+1; idx < nums2.size(); idx++){
                if(nums2[idx] > n){ans.push_back(nums2[idx]); found = true; break;}
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
};