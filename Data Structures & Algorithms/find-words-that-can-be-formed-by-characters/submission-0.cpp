class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> map(26,0);
        int count = 0;
        for(auto c: chars) map[c-'a']++;
        for(auto &word: words){
            vector<int> bmap(26,0);
            for(auto c: word) bmap[c-'a']++;
            bool flag = true;
            for(auto c: word){
                if(bmap[c-'a'] > map[c-'a']){flag = false; break;}
            }
            if(flag) count+=word.size();
        }
        return count;
    }
};