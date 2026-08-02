class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> myset;
        for(auto c: allowed) myset.insert(c);
        int count = 0;
        for(auto &word: words){
            bool flag = true;
            for(auto c: word){
                if(!myset.contains(c)){flag = false; break;} 
            }
            if(flag) count++;
        }
        return count;
    }
};