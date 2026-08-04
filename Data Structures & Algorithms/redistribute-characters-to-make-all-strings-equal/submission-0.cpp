class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> map(26,0);
        for(auto &word: words){
            for(auto c: word){
                map[c-'a']++;
            }
        }
        for(int i = 0; i < 26; i++){
            if(map[i]%words.size() != 0) return false;
        }
        return true;
    }
};
