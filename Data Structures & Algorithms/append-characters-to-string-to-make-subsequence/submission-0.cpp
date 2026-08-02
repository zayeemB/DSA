class Solution {
public:
    int appendCharacters(string s, string t) {
        int ps = 0, ts = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[ps] == t[ts])
                ts++;
            ps++;
        }

        return t.size()-ts;   
    }
};