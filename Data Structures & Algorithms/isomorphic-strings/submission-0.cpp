class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,char> mpa;
        unordered_map<char,char> mpb;
        for(int i = 0; i < t.size(); i++){
            if(!mpa.contains(s[i]) && !mpb.contains(t[i])){
                mpa[s[i]] = t[i];
                mpb[t[i]] = s[i];
            }
            else{
                if(mpa[s[i]] != t[i] || mpb[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};