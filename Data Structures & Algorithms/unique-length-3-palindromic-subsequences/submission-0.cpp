class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count = 0;
        for(int i = 0; i < 26; i++){
            char target = i+'a';
            
            int first = s.find(target);
            int last = s.rfind(target);

            if(first != string::npos && first < last){
                unordered_set<char> myset;
                for(int j = first+1; j < last; j++) myset.insert(s[j]);
                count += myset.size();
            }
        }
        return count;
    }
};