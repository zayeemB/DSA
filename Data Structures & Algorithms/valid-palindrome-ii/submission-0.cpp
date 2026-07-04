class Solution {
    bool recurse(int l, int r, bool flag, string &s){
        if(l >= r){
            return true;
        }
        if(s[l] != s[r] && !flag){
            if(s[l+1] == s[r] && recurse(l+1, r, true, s)) return true;
            if(s[l] == s[r-1] && recurse(l, r-1, true, s)) return true;
        }
        else if(s[l] == s[r]) return recurse(l+1, r-1, flag, s);
        return false;
    }
public:
    bool validPalindrome(string s) {
        return recurse(0, s.size()-1, false, s);
    }
};