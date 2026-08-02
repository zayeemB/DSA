class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        mp['b'] = 0; mp['a'] = 0; mp['l'] = 0; mp['o'] = 0; mp['n'] = 0;
        for(auto c: text){
            if(mp.contains(c)) mp[c]++;
        }
        mp['l'] /= 2;
        mp['o'] /= 2;
        int count = INT_MAX;
        for(auto &p: mp)
            count = min(count, p.second);
        return count;
    }
};