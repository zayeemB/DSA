class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ps = 0, ts = 0;

        for(int i = 0; i < t.size(); i++){
            if(s[ps] == t[ts]){
                ps++;
                ts++;
            }
            else ts++;
        }

        if(ps == s.size()) return true;
        return false;
    }
};