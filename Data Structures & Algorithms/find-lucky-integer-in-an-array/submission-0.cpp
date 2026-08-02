class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto n: arr)
            mp[n]++;
        int li = -1;
        for(auto &p: mp){
            if(p.first == p.second) li = max(li, p.first);
        }
        return li;
    }
};