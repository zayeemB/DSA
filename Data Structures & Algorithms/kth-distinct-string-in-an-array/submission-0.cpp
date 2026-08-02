class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> dst;
        unordered_map<string, int> map;
        for(auto &s: arr) map[s]++;
        for(auto &s: arr){
            if(map[s] == 1) dst.push_back(s);
        }
        if(k > dst.size()) return "";
        return dst[k-1];
    }
};