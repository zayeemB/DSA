class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mp;
        for(auto &c: s)
            mp[c]++;
        int minEven = INT_MAX;
        int maxOdd = INT_MIN;
        for(auto &p: mp){
            int c = p.second;
            if(c%2==0) minEven = min(minEven, c);
            else maxOdd = max(maxOdd, c);
        }
        return maxOdd - minEven;
    }
};