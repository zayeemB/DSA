class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mgmap(26,0), rnsmap(26,0);
        for(auto c: magazine) mgmap[c-'a']++;
        for(auto c: ransomNote) rnsmap[c-'a']++;
        for(auto c: ransomNote){
            if(rnsmap[c-'a'] > mgmap[c-'a']) return false;
        }
        return true;
    }
};